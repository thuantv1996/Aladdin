#include "MyGraphics.h"


MyGraphics::MyGraphics()
{
}


void MyGraphics::init_Graphit(LPDIRECT3DDEVICE9 d3ddv)
{
	// tao tam giac
	vertices = new CUSTOMVERTEX[3];
	vertices[0] = { 320.0f, 50.0f, 0.5f, 1.0f, D3DCOLOR_XRGB(0, 0, 255) };
	vertices[1] = { 520.0f, 400.0f, 0.5f, 1.0f, D3DCOLOR_XRGB(0, 255, 0) };
	vertices[2] = { 120.0f, 400.0f, 0.5f, 1.0f, D3DCOLOR_XRGB(255, 0, 0) };

	// tao vertex buffer
	d3ddv->CreateVertexBuffer(sizeof(CUSTOMVERTEX)* 3, 0, CUSTOMFVF, D3DPOOL_MANAGED, &v_buffer, NULL);
	VOID *pVoid;
	v_buffer->Lock(0, 0, (void**)&pVoid, 0);
	memcpy(pVoid, vertices, sizeof(vertices));
	v_buffer->Unlock();
}

void MyGraphics::Draw(LPDIRECT3DDEVICE9 d3ddv)
{
	d3ddv->SetFVF(CUSTOMFVF);
	d3ddv->SetStreamSource(0, v_buffer, 0, sizeof(CUSTOMVERTEX));
	d3ddv->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
}

MyGraphics::~MyGraphics()
{
	v_buffer->Release();
	free(vertices);
}
