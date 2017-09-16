#include "Camera.h"
#include "GraphicsDevice.h"

Camera::Camera(){}

void Camera::createCamera(GraphicsDevice *graphics,float width,float height,float nearClip, float farClip)
{
	// Xác định vùng nhìn, hệ số co và mặt phẳng clipping xa, gần
	D3DXMatrixOrthoLH(&matProj, 800, -600, nearClip, farClip);
	// thiết lập ma trận matProj cho giai đoạn chiếu
	graphics->device->SetTransform(D3DTS_PROJECTION, &matProj);
	//thiết lập các tham số cho đối tượng
	box.width = width;
	box.height = height;
	box.x = width / 2;
	box.y = height / 2;
	box.vx = 0;
	box.vy = 0;
}

void Camera::pointCamera(GraphicsDevice *graphics,D3DXVECTOR3 cameraPosition, D3DXVECTOR3 cameraLook)
{
	if (isFollow())
	{
		cameraLook.x = follow->getBox().x;
		cameraLook.y = follow->getBox().y;
		cameraPosition.x = follow->getBox().x;
		cameraPosition.y = follow->getBox().y;
		box.x = follow->getBox().x;
		box.y = follow->getBox().y;
		box.vx = follow->getBox().vx;
		box.vy = follow->getBox().vy;
	}
	D3DXMatrixLookAtLH(&matView,
		&cameraPosition, // vị trí camera
		&cameraLook, // điểm nhìn
		&D3DXVECTOR3(0.0f, 1.0f, 0.0f)); // hướng lên trên
	// thiết lập ma trận này cho giai đoạn view
	graphics->device->SetTransform(D3DTS_VIEW, &matView);
}

void Camera::Follow(GameplayObject *f)
{
	follow = f;
}

bool Camera::isFollow()
{
	return follow != NULL;
}

void Camera::UnFollow()
{
	delete (follow);
	follow = NULL;
}




