#ifndef CAMERA_H
#define CAMERA_H

#include <DirectXMath.h>
#include"GraphicsDevice.h"
#include"GameplayObject.h"


class Camera: public GameplayObject
{
public:
	/* Constructor */
	Camera();

	/* Tạo camera */
	void createCamera(GraphicsDevice *graphics, float width, float height, float nearClip, float farClip);

	/* Đặt điểm nhìn cho camera */
	void pointCamera(GraphicsDevice *graphics,D3DXVECTOR3 cameraPosition, D3DXVECTOR3 cameraLook);

	/* Theo dõi đối tượng */
	void Follow(GameplayObject *f);

	/*Kiễm tra sự theo dõi*/
	bool isFollow();

	/* Ngừng theo dõi */
	void UnFollow();


private:
	D3DXMATRIX matProj; // ma trận chiếu
	D3DXMATRIX matView; // ma trận view
	GameplayObject *follow;
	BOX box;// Hộp xét va chạm
};

#endif /* CAMERA_H */
