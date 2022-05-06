
// SteamBalanceDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SteamBalance.h"
#include "SteamBalanceDlg.h"
#include "afxdialogex.h"

#define floors 100.000f

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CSteamBalanceDlg �Ի���



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
	, m_name(_T(""))
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
	DDX_Text(pDX, IDC_EDIT14, m_name);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_BUTTON3, m_btm3);
}

BEGIN_MESSAGE_MAP(CSteamBalanceDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSteamBalanceDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSteamBalanceDlg::OnBnClickedButton2)
	ON_WM_CLOSE()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON4, &CSteamBalanceDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CSteamBalanceDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON3, &CSteamBalanceDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CSteamBalanceDlg ��Ϣ�������

BOOL CSteamBalanceDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	m_chargeper = 0.13043478 * 100;
	m_price = 15.1;
	m_steamprice = 21.85;
	m_getprice = 303;

	// EnableToolTips(TRUE);//enable use it
	m_ctrlTT.Create(this);
	m_ctrlTT.Activate(TRUE);
	m_ctrlTT.SetTipTextColor(RGB(0, 0, 255));//font color
	m_ctrlTT.SetDelayTime(2000,150);//delay time

	// ���ؼ������ʾ��Ϣ
	m_ctrlTT.AddTool(GetDlgItem(IDC_EDIT3), _T("���̶����赽Steam�����г���ʵ"));

	m_ctrlTT.AddTool(GetDlgItem(IDC_EDIT5), _T("����������"));
	m_ctrlTT.AddTool(GetDlgItem(IDC_EDIT6), _T("����׬�˶���Ǯ"));
	m_ctrlTT.AddTool(GetDlgItem(IDC_EDIT7), _T("һ��׬�˶���Ǯ"));
	m_ctrlTT.AddTool(GetDlgItem(IDC_EDIT9), _T("һ��Ҫ������Ǯ"));
	m_ctrlTT.AddTool(GetDlgItem(IDC_EDIT10), _T("�൱���Լ����������"));
	m_ctrlTT.AddTool(GetDlgItem(IDC_EDIT13), _T("������Ҫ�����������"));

	// ��Ϣ����
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	CString field[] = { _T("��Ʒ����"), _T("ƽ̨�۸�"), _T("�г��۸�"), _T("����"),_T("�ܵ���"), _T("�ܻ���"), _T("�ۿ���") };
	m_list.InsertColumn(1, field[0], LVCFMT_CENTER, 120);
	m_list.InsertColumn(2, field[1], LVCFMT_CENTER, 70);
	m_list.InsertColumn(3, field[2], LVCFMT_CENTER, 70);
	m_list.InsertColumn(4, field[3], LVCFMT_CENTER, 50);
	m_list.InsertColumn(5, field[4], LVCFMT_CENTER, 60);
	m_list.InsertColumn(6, field[5], LVCFMT_CENTER, 60);
	m_list.InsertColumn(7, field[6], LVCFMT_CENTER, 60);
	SetWindowPos(NULL, 0, 0, 594, 384, SWP_NOMOVE);
	UpdateData(FALSE);
	inf.clear();//��սṹ���б�����
	count = 0;
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSteamBalanceDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CSteamBalanceDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSteamBalanceDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_steamprice == 0 || m_price == 0 || m_getprice == 0)
	{
		MessageBox(_T("��������Ч���ݣ�"), _T("����"), MB_ICONWARNING);
		return;
	}
	if (m_steamprice <= m_price)
	{
		MessageBox(_T("�г��۸�������ƽ̨�۸�"), _T("����"), MB_ICONWARNING);
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
	//�ĳɱ�����λС��
	mc_oneprice = floor(mc_oneprice * floors + 0.5) / floors;
	mc_onecharge = floor(mc_onecharge * floors + 0.5) / floors;
	mc_onediffprice = floor(mc_onediffprice * floors + 0.5) / floors;
	mc_allprice = floor(mc_allprice * floors + 0.5) / floors;
	mc_allcharge = floor(mc_allcharge * floors + 0.5) / floors;
	mc_alldiffprice = floor(mc_alldiffprice * floors + 0.5) / floors;
	mc_allpay = floor(mc_allpay * floors + 0.5) / floors;
	mc_discount = floor(mc_discount * floors + 0.5) / floors;

	//�浽�ṹ���б�����
	Info temp;
	if (m_name.IsEmpty())
	{
		temp.name = "��Ʒ";
	}
	else
		temp.name = CT2A(m_name.GetBuffer());//unioncode����ת��
	temp.discount = mc_discount;
	temp.dqpay = mc_allprice;
	temp.hfpay = mc_allpay;
	temp.num = mc_num;
	temp.ptprice = m_price;
	temp.sqprice = m_steamprice;

	//������ˢ���ؼ���
	CString str;
	int w = 1;
	str = CA2T(temp.name.c_str());
	m_list.InsertItem(count, str);
	str.Format(_T("%.2lf"), temp.ptprice);
	m_list.SetItemText(count, w++, str);
	str.Format(_T("%.2lf"), temp.sqprice);
	m_list.SetItemText(count, w++, str);
	str.Format(_T("%d"), temp.num);
	m_list.SetItemText(count, w++, str);
	str.Format(_T("%.2lf"), temp.dqpay);
	m_list.SetItemText(count, w++, str);
	str.Format(_T("%.2lf"), temp.hfpay);
	m_list.SetItemText(count, w++, str);
	str.Format(_T("%.2lf%%"), temp.discount);
	m_list.SetItemText(count, w++, str);
	inf.push_back(temp);
	UpdateData(FALSE);
}


void CSteamBalanceDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	m_name.Empty();
	UpdateData(FALSE);
}


BOOL CSteamBalanceDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	m_ctrlTT.RelayEvent(pMsg);
	return CDialogEx::PreTranslateMessage(pMsg);
}

void CSteamBalanceDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	OnBnClickedButton1();
}


void CSteamBalanceDlg::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnCancel();
}
void CSteamBalanceDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	EndDialog(IDCANCEL);//ȡ���¼���д�ˣ��رհ�ťʧЧ�ˣ����������رհ�ť
	CDialogEx::OnClose();
}


HBRUSH CSteamBalanceDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if (pWnd->GetDlgCtrlID() == IDC_TEXT1)//�޸Ŀؼ���ɫ
	{
		pDC->SetTextColor(RGB(255, 0, 0));//��RGB��ı���ɫ 
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}

void CSteamBalanceDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//�޸Ĵ��ڴ�С
	UpdateData(TRUE);
	CString str, t1, t2;
	t1 = _T("��ϸ��Ϣ>>");
	t2 = _T("��ϸ��Ϣ<<");
	m_btm3.GetWindowTextW(str);
	if (str == t2)
	{
		SetWindowPos(NULL, 0, 0, 594, 384, SWP_NOMOVE);
		m_btm3.SetWindowTextW(t1);
	}
	else
	{
		SetWindowPos(NULL, 0, 0, 594, 604, SWP_NOMOVE);
		m_btm3.SetWindowTextW(t2);
	}
	UpdateData(FALSE);
}

void CSteamBalanceDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_list.DeleteAllItems();
	inf.clear();
	count = 0;
}


void CSteamBalanceDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ofstream ofs;
	CString gReadFilePathName;
	CFileDialog fileDlg(FALSE, _T("csv"), _T("��Ϣ����"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("Excel��� (*.csv)|.csv|�ı��ĵ� (*.txt)|*.txt|All File (*.*)|*.*||"), NULL);
	if (fileDlg.DoModal() == IDOK)    //�����Ի���
	{
		gReadFilePathName = fileDlg.GetPathName();
		//AfxMessageBox(_T("OK"));
		ofs.open(gReadFilePathName.GetBuffer(), ios::out | ios::trunc);
		ofs << "��Ʒ����," << "ƽ̨�۸�," << "�г��۸�," << "����," << "�ܵ���," << "�ܻ���," << "�ۿ���" << endl;
		list<Info>::iterator it;
		for (it = inf.begin(); it != inf.end(); it++)
		{
			ofs << it->name.c_str() << ",";
			ofs << fixed << setprecision(2);
			ofs << it->ptprice << ",";
			ofs << it->sqprice << ",";
			ofs << it->num << ",";
			ofs << it->dqpay << ",";
			ofs << it->hfpay << ",";
			ofs << it->discount << "%";
			ofs << endl;
		}
		ofs.close();
		MessageBox(_T("����ɹ���"), _T("��ʾ"), MB_ICONINFORMATION);
	}
}


