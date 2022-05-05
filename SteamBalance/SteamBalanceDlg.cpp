
// SteamBalanceDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SteamBalance.h"
#include "SteamBalanceDlg.h"
#include "afxdialogex.h"

#define floors 100.000f

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSteamBalanceDlg 对话框



CSteamBalanceDlg::CSteamBalanceDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_STEAMBALANCE_DIALOG, pParent)
	, m_steamprice(0)
	, m_price(0)
	, m_chargeper(0)
	, mc_oneprice(0)
	, mc_allprice(0)
	, mc_onecharge(0)
	, mc_onediffprice(0)
	, mc_num(0)
	, m_getprice(0)
	, mc_allpay(0)
	, mc_allcharge(0)
	, mc_alldiffprice(0)
	, mc_discount(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSteamBalanceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_steamprice);
	DDX_Text(pDX, IDC_EDIT2, m_price);
	DDX_Text(pDX, IDC_EDIT3, m_chargeper);
	DDX_Text(pDX, IDC_EDIT4, mc_oneprice);
	DDX_Text(pDX, IDC_EDIT5, mc_allprice);
	DDX_Text(pDX, IDC_EDIT11, mc_onecharge);
	DDX_Text(pDX, IDC_EDIT6, mc_onediffprice);
	DDX_Text(pDX, IDC_EDIT8, mc_num);
	DDX_Text(pDX, IDC_EDIT13, m_getprice);
	DDX_Text(pDX, IDC_EDIT9, mc_allpay);
	DDX_Text(pDX, IDC_EDIT12, mc_allcharge);
	DDX_Text(pDX, IDC_EDIT7, mc_alldiffprice);
	DDX_Text(pDX, IDC_EDIT10, mc_discount);
}

BEGIN_MESSAGE_MAP(CSteamBalanceDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSteamBalanceDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSteamBalanceDlg::OnBnClickedButton2)
	ON_WM_CLOSE()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CSteamBalanceDlg 消息处理程序

BOOL CSteamBalanceDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_chargeper = 0.13043478 * 100;
	// EnableToolTips(TRUE);//enable use it
	m_ctrlTT.Create(this);
	m_ctrlTT.Activate(TRUE);
	m_ctrlTT.SetTipTextColor(RGB(0, 0, 255));//font color
	m_ctrlTT.SetDelayTime(2000,150);//delay time

	// 给控件添加提示信息
	m_ctrlTT.AddTool(GetDlgItem(IDC_EDIT3), _T("不固定，需到Steam社区市场核实"));
	m_ctrlTT.AddTool(GetDlgItem(IDC_EDIT6), _T("单个赚了多少钱"));
	m_ctrlTT.AddTool(GetDlgItem(IDC_EDIT7), _T("一共赚了多少钱"));
	m_ctrlTT.AddTool(GetDlgItem(IDC_EDIT5), _T("倒出来总数"));
	m_ctrlTT.AddTool(GetDlgItem(IDC_EDIT10), _T("相当于以几折买了余额"));

	UpdateData(FALSE);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSteamBalanceDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSteamBalanceDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSteamBalanceDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSteamBalanceDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_steamprice == 0 || m_price == 0 || m_getprice == 0)
	{
		MessageBox(_T("请输入有效数据！"), _T("警告"), MB_ICONWARNING);
		return;
	}
	mc_oneprice = m_steamprice * (1 - m_chargeper / 100);
	mc_onecharge = m_steamprice*m_chargeper / 100;
	mc_onediffprice = mc_oneprice - m_price;
	if ((int)(m_getprice / mc_oneprice) == (m_getprice / mc_oneprice))
		mc_num = (int)(m_getprice / mc_oneprice);
	else
		mc_num = (int)(m_getprice / mc_oneprice) + 1;
	mc_allprice = mc_num*mc_oneprice;
	mc_allcharge = mc_onecharge*mc_num;
	mc_alldiffprice = mc_onediffprice*mc_num;
	mc_allpay = m_price*mc_num;
	mc_discount = mc_allpay / mc_allprice;
	mc_discount *= 100;
	//改成保留两位小数
	mc_oneprice = floor(mc_oneprice * floors + 0.5) / floors;
	mc_onecharge = floor(mc_onecharge * floors + 0.5) / floors;
	mc_onediffprice = floor(mc_onediffprice * floors + 0.5) / floors;
	mc_allprice = floor(mc_allprice * floors + 0.5) / floors;
	mc_allcharge = floor(mc_allcharge * floors + 0.5) / floors;
	mc_alldiffprice = floor(mc_alldiffprice * floors + 0.5) / floors;
	mc_allpay = floor(mc_allpay * floors + 0.5) / floors;
	mc_discount = floor(mc_discount * floors + 0.5) / floors;
	UpdateData(FALSE);
}





void CSteamBalanceDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_chargeper = 0.13043478 * 100;
	m_getprice = 0;
	m_hIcon = 0;
	m_price = 0;
	m_steamprice = 0;
	mc_allcharge = 0;
	mc_alldiffprice = 0;
	mc_allpay = 0;
	mc_allprice = 0;
	mc_discount = 0;
	mc_num = 0;
	mc_onecharge = 0;
	mc_onediffprice = 0;
	mc_oneprice = 0;
	UpdateData(FALSE);
}


BOOL CSteamBalanceDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	m_ctrlTT.RelayEvent(pMsg);
	return CDialogEx::PreTranslateMessage(pMsg);
}

void CSteamBalanceDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	OnBnClickedButton1();
}


void CSteamBalanceDlg::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnCancel();
}
void CSteamBalanceDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	EndDialog(IDCANCEL);//取消事件重写了，关闭按钮失效了，重新启动关闭按钮
	CDialogEx::OnClose();
}


HBRUSH CSteamBalanceDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd->GetDlgCtrlID() == IDC_TEXT1)//修改控件颜色
	{
		pDC->SetTextColor(RGB(255, 0, 0));//用RGB宏改变颜色 
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
