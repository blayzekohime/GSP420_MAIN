#pragma once

#include "D3DUtils.h"

#define WND_CAPTION_LEN		64

namespace GFXCore
{
	class D3DCore
	{
	public:
		// functionality	///////////////////////////////////////////////////
		bool initGfxCore(const HINSTANCE hInst, const wchar_t* wndCaption,
								const int width = 1024, const int height = 768, 
								const D3DDEVTYPE requestedDevtype = D3DDEVTYPE_HAL,
								const DWORD requestedVP = D3DCREATE_HARDWARE_VERTEXPROCESSING);
		void shutdown();
		void updateScene(const float dt);
		void drawScene();
		void onLostDevice();
		void onResetDevice();
		bool checkDeviceCaps();
		bool isDeviceLost();
		void setFullScreenMode(bool enable);
	//	LRESULT msgProc(UINT msg, WPARAM wParam, LPARAM lParam);
		LRESULT CALLBACK msgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

		// accessors ////////////////////////////////////////////////////////
		inline HINSTANCE	getAppInstance() const;
		inline HWND			getHWND() const;
		inline wchar_t		getWinCaption() const;
		inline IDirect3DDevice9* getDevice() const;
		inline int getWndHeight() const;
		inline int getWndWidth() const;
		inline D3DPRESENT_PARAMETERS& getPresentParams();

		static inline D3DCore* get();

	protected:
		D3DDEVTYPE			deviceType;
		D3DPRESENT_PARAMETERS	presentParams;

		wchar_t		strMainWndCaption[WND_CAPTION_LEN];

		int		nWidth;
		int		nHeight;

		DWORD		dwRequestedVP;

		static IDirect3DDevice9*	pD3DDevice;
		static IDirect3D9*			pD3DObject;

		HWND				hHwnd;
		HINSTANCE		hInstance;

		bool initMainWnd(const HINSTANCE hInst, const wchar_t* wndCaption, const int width, const int height);
		bool initDirect3D(const D3DDEVTYPE requestedDevtype, const DWORD requestedVP);

		D3DCore();
		virtual ~D3DCore();

		// HACK: for now
	public:
		inline void beginScene(const D3DCOLOR clearColor);
		inline void endScene();

	private:
		static D3DCore*	pInstance;
		static inline void del();
	};

	// inline function definitions //////////////////////////////////////////
	HINSTANCE D3DCore::getAppInstance() const	{ return get()->hInstance; }
	HWND D3DCore::getHWND() const { return get()->hHwnd; }
	IDirect3DDevice9* D3DCore::getDevice() const { return get()->pD3DDevice; }
	wchar_t D3DCore::getWinCaption() const { return get()->strMainWndCaption[WND_CAPTION_LEN]; }
	int D3DCore::getWndHeight() const { return get()->nHeight; }
	int D3DCore::getWndWidth() const  { return get()->nWidth; }
	D3DPRESENT_PARAMETERS& D3DCore::getPresentParams()  { return get()->presentParams; }

	void D3DCore::beginScene(const D3DCOLOR clearColor) {
		HR(pD3DDevice->Clear(0, NULL, D3DCLEAR_STENCIL | D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clearColor, 1.0f, 0));
		HR(pD3DDevice->BeginScene());
	}
	void D3DCore::endScene() {
		HR(pD3DDevice->EndScene());
		HR(pD3DDevice->Present(0, 0, 0, 0));
	}

	D3DCore* D3DCore::get() {
		if (NULL == pInstance)
			pInstance = new D3DCore;
		return pInstance;
	}

	void D3DCore::del() {
		if (pInstance) {
			delete pInstance;
			pInstance = NULL;
		}
	}
}