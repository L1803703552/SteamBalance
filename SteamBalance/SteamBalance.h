
// SteamBalance.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSteamBalanceApp: 
// �йش����ʵ�֣������ SteamBalance.cpp
//

class CSteamBalanceApp : public CWinApp
{
public:
	CSteamBalanceApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSteamBalanceApp theApp;