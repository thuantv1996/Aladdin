#pragma once
#include<d3d9.h>
#define CUSTOMFVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

//cau truc dinh dang dinh trong Direct 3D
struct CUSTOMVERTEX{
	FLOAT x, y, z, rhw; // lay tu co hieu D3DFVF_XYZRHW
	DWORD color;// mau sac cac dinh

};

class MyGraphics
{
protected:
	CUSTOMVERTEX *vertices;
	LPDIRECT3DVERTEXBUFFER9 v_buffer;
public:
	MyGraphics();
	void init_Graphit(LPDIRECT3DDEVICE9);
	void Draw(LPDIRECT3DDEVICE9);
	~MyGraphics();
};

