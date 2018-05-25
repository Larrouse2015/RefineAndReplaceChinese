
// RefineAndReplaceChineseDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RefineAndReplaceChinese.h"
#include "RefineAndReplaceChineseDlg.h"
#include "afxdialogex.h"
#include "EasySize.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRefineAndReplaceChineseDlg �Ի���




CRefineAndReplaceChineseDlg::CRefineAndReplaceChineseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRefineAndReplaceChineseDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRefineAndReplaceChineseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_IMPORT_BTN, import_btn);
	DDX_Control(pDX, IDC_UPLOAD_BTN, upload_btn);
	DDX_Control(pDX, IDC_REPLACE_BTN, replace_btn);
	DDX_Control(pDX, IDC_INFO, m_info);
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	DDX_Control(pDX, IDC_DOSELF_BTN, doself_btn);
	DDX_Control(pDX, IDC_SELF_PATH, selfpath);
	DDX_Control(pDX, IDC_RPSRC_BTN, rpsrc_btn);
}

BEGIN_MESSAGE_MAP(CRefineAndReplaceChineseDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_IMPORT_BTN, &CRefineAndReplaceChineseDlg::OnBnClickedImportBtn)
	ON_BN_CLICKED(IDC_UPLOAD_BTN, &CRefineAndReplaceChineseDlg::OnBnClickedUploadBtn)
	ON_BN_CLICKED(IDC_REPLACE_BTN, &CRefineAndReplaceChineseDlg::OnBnClickedReplaceBtn)
	ON_BN_CLICKED(IDC_DOSELF_BTN, &CRefineAndReplaceChineseDlg::OnBnClickedDoselfBtn)
	ON_BN_CLICKED(IDC_RPSRC_BTN, &CRefineAndReplaceChineseDlg::OnBnClickedRpsrcBtn)
	ON_WM_SIZE()
	ON_WM_SIZING()
	ON_BN_CLICKED(IDC_OUT_BTN, &CRefineAndReplaceChineseDlg::OnBnClickedOutBtn)
END_MESSAGE_MAP()

BEGIN_EASYSIZE_MAP(CRefineAndReplaceChineseDlg)
	EASYSIZE(IDC_LIST1,ES_BORDER,ES_BORDER,IDC_IMPORT_BTN,ES_BORDER,0)
	EASYSIZE(IDC_MIDFRAME,ES_BORDER,ES_BORDER,ES_BORDER,ES_BORDER,0)
	EASYSIZE(IDC_IMPORT_BTN,ES_KEEPSIZE,ES_BORDER,ES_BORDER,ES_KEEPSIZE,0)
	EASYSIZE(IDC_REPLACE_BTN,ES_KEEPSIZE,ES_BORDER,ES_BORDER,ES_KEEPSIZE,0)
	EASYSIZE(IDC_UPLOAD_BTN,ES_KEEPSIZE,ES_BORDER,ES_BORDER,ES_KEEPSIZE,0)
	EASYSIZE(IDC_DOSELF_BTN,ES_KEEPSIZE,ES_BORDER,ES_BORDER,ES_KEEPSIZE,0)
	EASYSIZE(IDC_RPSRC_BTN,ES_KEEPSIZE,ES_BORDER,ES_BORDER,ES_KEEPSIZE,0)
	EASYSIZE(IDC_SELF_PATH,ES_KEEPSIZE,ES_BORDER,ES_BORDER,ES_KEEPSIZE,0)
	EASYSIZE(IDC_INFO,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
	EASYSIZE(IDC_PROGRESS1,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,ES_BORDER,0)
END_EASYSIZE_MAP

// CRefineAndReplaceChineseDlg ��Ϣ�������

BOOL CRefineAndReplaceChineseDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	ShowWindow(SW_SHOWNORMAL);

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//�����ʼ���Լ����ݿ��ʼ��
	INIT_EASYSIZE;
	logx_line=0;
	logy_line=0;
	log_line=0;
	sql_line=0;
	import_btn.EnableWindow(true);
	doself_btn.EnableWindow(true);
	upload_btn.EnableWindow(false);
	replace_btn.EnableWindow(false);
	rpsrc_btn.EnableWindow(false);
	import_btn.EnableWindow(false);
	m_sum=0;
	trans_num=0;
	m_list.InsertColumn(0,"����",LVCFMT_LEFT,40);
	m_list.InsertColumn(1,"�ļ���",LVCFMT_LEFT,80);
	m_list.InsertColumn(2,"�ļ�·��",LVCFMT_LEFT,200);
	m_list.InsertColumn(3,"�ļ�����",LVCFMT_LEFT,40);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	initMySql();
	//����һЩ�ļ������ڴ������н������־�ļ�
	_mkdir("./log");
	_mkdir("./result");
	//��ȡ���ڴ�С��Ϊ����Ӧ��С��׼��
	CRect rect;
	GetWindowRect(&rect);
	min_hight=rect.Height();
	min_width=rect.Width();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CRefineAndReplaceChineseDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CRefineAndReplaceChineseDlg::OnPaint()
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
HCURSOR CRefineAndReplaceChineseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CRefineAndReplaceChineseDlg::ScanFile(CString Dir)
{
	CFileFind finder;
	CString Add="\\*";
	CString DirSpec=Dir+Add;
	bool bWorking=finder.FindFile(DirSpec);

	CString path;
	CString name;
	CString sufi;
	CString ss;
	int r;

	while(bWorking)
	{
		bWorking=finder.FindNextFile();
		if(!finder.IsDots())
		{
			if(finder.IsDirectory())
			{
				CString strDirectory=finder.GetFilePath();
				ScanFile(strDirectory);
			}
			else
			{
				path=finder.GetFilePath();
				name=finder.GetFileName();
				if(doHand[name.GetBuffer(name.GetLength())])
					continue;
				sufi=name.Right(3);
				if(sufi=="lua"||sufi=="hrl")
				{
					ss.Format("%03d",m_sum);
					r=m_list.InsertItem(m_sum,ss);
					m_sum++;
					m_list.SetItemText(r,0,ss);
					m_list.SetItemText(r,1,name);
					m_list.SetItemText(r,2,path);
					if(sufi=="lua")
						m_list.SetItemText(r,3,"lua");
					if(sufi=="hrl")
						m_list.SetItemText(r,3,"hrl");
				}
				sufi=name.Right(6);
				if(sufi=="config")
				{
					ss.Format("%03d",m_sum);
					r=m_list.InsertItem(m_sum,ss);
					m_sum++;
					m_list.SetItemText(r,0,ss);
					m_list.SetItemText(r,1,name);
					m_list.SetItemText(r,2,path);
					m_list.SetItemText(r,3,"config");
				}
			}
		}
	}
}

//����һ���ļ������������xml,config,hrl�ļ��������ļ���������ļ���
void CRefineAndReplaceChineseDlg::OnBnClickedImportBtn()
{
	// TODO: Add your control notification handler code here
	BROWSEINFO bi;
	::ZeroMemory(&bi,sizeof(bi));
	LPITEMIDLIST target=SHBrowseForFolder(&bi);
	if(target!=NULL)
	{
		char targetpath[MAX_PATH];
		SHGetPathFromIDList(target,targetpath);
		CString Dir;
		Dir.Format("%s",targetpath);
		ScanFile(Dir);
	}
	upload_btn.EnableWindow(true);
	replace_btn.EnableWindow(true);
}

//���ݿ�ĳ�ʼ�������ұ��ط������ӵ�bingshen���ݿ�
void CRefineAndReplaceChineseDlg::initMySql(void)
{
	if(mysql_library_init(0,NULL,NULL))
		AfxMessageBox("mysql_library_init() failed");
	if(mysql_init(&mydata)==NULL)
		AfxMessageBox("mysql_init() failed");
	if(mysql_options(&mydata,MYSQL_SET_CHARSET_NAME,"utf8"))
		AfxMessageBox("mysql_options() failed");
	fstream sqlcfg("mysql.cfg");
	sqlcfg>>m_sqlip>>m_sqlname>>m_sqlpassword>>m_sqltable;
	if(mysql_real_connect(&mydata,m_sqlip.c_str(),m_sqlname.c_str(),m_sqlpassword.c_str(),m_sqltable.c_str(),3306,NULL,0)==NULL)
		AfxMessageBox("mysql_real_connect() failed\n");
	CString sqlstr;
	sqlstr="DESC test";
	MYSQL_RES *result=NULL;
	MYSQL_ROW row=NULL;
	if(0==mysql_query(&mydata,sqlstr.GetBuffer(sqlstr.GetLength())))
	{
		result=mysql_store_result(&mydata);
		row=mysql_fetch_row(result);
		while(row)
		{
			if(strcmp(row[0],"id")==0)
			{
				row=mysql_fetch_row(result);
				continue;
			}
			if(strcmp(row[0],"key")==0)
			{
				row=mysql_fetch_row(result);
				continue;
			}
			if (strcmp(row[0], "chinese") == 0)
			{
				row = mysql_fetch_row(result);
				continue;
			}
			trans_Field[trans_num++]=row[0];
			//selectlanguage.AddString(row[0]);
			row=mysql_fetch_row(result);
		}
	}
	now_trans=2;
}

//�ϴ����ݵ����ݿ�
void CRefineAndReplaceChineseDlg::OnBnClickedUploadBtn()
{
	// TODO: Add your control notification handler code here
	LockAllBtn();
	GetQuotes();
	GetSqlFile();
	DoMap();
	CreateTableAndUpload();
	ReleaseAllBtn();
	m_info.SetWindowTextA("");
	m_progress.SetPos(0);
}

//��һ����������ȡ�����е����Ķ�
char* GetChinese(char* ch)
{
	int i,l,t,ppos;
	char *put;
	char *tmp;
	bool flag=true,loop=false,is_chi=false;
	put=(char*)malloc(strlen(ch)+1);
	tmp=(char*)malloc(strlen(ch)+1);
	l=strlen(ch);
	if(l>0)
		put[0]='\0';
	t=0;
	for(i=0;i<l;i++)
	{
		if(ch[i]=='\"'&&flag==true)
		{
			flag=false;
			loop=true;
			continue;
		}
		if(ch[i]=='\"'&&flag==false)
		{
			flag=true;
			loop=false;
			tmp[t++]=' ';
			tmp[t++]='$';
			tmp[t++]='\0';
			if(is_chi)
			{
				strcat(put,tmp);
			}
			t=0;
			tmp[0]='\0';
			is_chi=false;
			continue;
		}
		if(loop)
		{
			if(ch[i]=='\\')
			{
				ch[i]='~';
			}else if(ch[i] == ' ')
			{
				ch[i] = '^';
			}

			tmp[t++]=ch[i];
			if(ch[i]<0)				//ascii �ַ�Ϊ0-127  ����� <0 ���ַ������ʾ���������ַ��� ���纺�֣����ģ��ȵ�
				is_chi=true;	
		}
	}
	return put;
}



//��ȡ�����ļ��е��������Ķ����ݣ����Ҵ�������־�ļ�logx.txt��
void CRefineAndReplaceChineseDlg::GetQuotes(void)
{
	int i,j;
	CFile file("./log\\logx.txt",CFile::modeWrite|CFile::modeCreate);
	m_progress.SetRange(0,m_sum-1);
	for(i=0;i<m_sum;i++)
	{
		CString path,name,info;
		int now_line=0;
		path=m_list.GetItemText(i,2);
		name=m_list.GetItemText(i,1);
		CStdioFile f_sfile;
		CString lcs_FileContent;
		char ls_Msg[50000];
		if(!f_sfile.Open(path,CFile::modeRead))
		{
			MessageBox("�����޷��򿪵��ļ���");
			return;
		}
		info="��"+name+"�г�ȡ������������";
		m_info.SetWindowTextA(info);
		m_progress.SetPos(i);
		char *output,infile[5000],line[100],key[100];
		while(f_sfile.ReadString(lcs_FileContent))
		{
			logx_line++;
			int t=0;
			sprintf(ls_Msg,"%s",lcs_FileContent);
			output=GetChinese(ls_Msg);
			now_line++;
			sprintf(line," %d %s",now_line,name);
			int len=strlen(output);
			for(j=0;j<len;j++)
			{
				if(output[j]==' '&&output[j+1]=='$')
				{
					infile[t++]='\0';
					strcat(infile,line);
					file.Write(infile,strlen(infile));
					file.Write("\r\n\0",strlen("\r\n"));
					t=0;
					j=j+1;
					continue;
				}
				else
					infile[t++]=output[j];
			}
		}
		f_sfile.Close();
	}
	file.Close();
}



/*��logx.txt��logy.txt�ļ��ϲ�Ϊlog.txt
��logx.txt��logy.txt�ļ����Ǽ�¼��ÿ���������ڵ��ļ��������ڸ��ļ��е���һ��
�ϲ�Ϊlog.txt֮����ȥ���˶������Ϣֻ���������Ķ�
���ﱾ�����Բ�������logx��logy�ļ���ֱ������log
�����������Ļ����������������޷���ȷ֪�����ĸ��ļ�����һ�г���*/
void CRefineAndReplaceChineseDlg::GetSqlFile(void)
{
	CString info;
	CFile file("./log\\log.txt",CFile::modeWrite|CFile::modeCreate);
	CStdioFile f_sfile;
	CString lcs_FileContent,writetolog;
	int len,i,count=0;
	char ls_Msg[50000];
	if(!f_sfile.Open("./log\\logx.txt",CFile::modeRead))
	{
		MessageBox("�޷���logx.txt��");
		return;
	}
	m_progress.SetRange(0,logx_line);
	info="��logx.txt�кϲ����ݵ�log.txt��";
	m_info.SetWindowTextA(info);
	while(f_sfile.ReadString(lcs_FileContent))
	{
		log_line++;
		sprintf(ls_Msg,"%s",lcs_FileContent);
		len=strlen(ls_Msg);
		for(i=0;i<len;i++)
		{
			if(ls_Msg[i]==' ')
			{
				ls_Msg[i]='\r';
				ls_Msg[i+1]='\n';
				ls_Msg[i+2]='\0';
				break;
			}
			if(ls_Msg[i]=='^')
				ls_Msg[i]=' ';
		}
		file.Write(ls_Msg,strlen(ls_Msg));
		count++;
		m_progress.SetPos(count);
	}
	f_sfile.Close();
	file.Close();
}

/*����ʹ�ú����map��log.txt�е��ظ����ݽ���ɾ��
����һ���Ż�������ֱ���ϴ������Ѿ�ȥ���ص�����
��Ȼ���ϴ���mysql��ʱ��Ҳ��ȥ�أ�����Ч�ʿ϶��ǲ��籾�ص������ٶ�
����log.txt֮��õ����ظ��ļ�sql.txt*/
void CRefineAndReplaceChineseDlg::DoMap(void)
{
	rep.clear();
	CStdioFile f_sfile;
	CString str,info;
	CFile file("./log\\sql.txt",CFile::modeWrite|CFile::modeCreate);
	if(!f_sfile.Open("./log\\log.txt",CFile::modeRead))
	{
		MessageBox("�޷���log.txt��");
		return;
	}
	m_progress.SetRange(0,log_line);
	info="��log.txt��ɾ���ظ�����";
	m_info.SetWindowTextA(info);
	int count=0;
	while(f_sfile.ReadString(str))
	{
		count++;
		if(rep[str.GetBuffer(str.GetLength())]==false)
		{
			rep[str.GetBuffer(str.GetLength())]=true;
			str+="\r\n\0";
			file.Write(str.GetBuffer(str.GetLength()),str.GetLength());
			sql_line++;
		}
		m_progress.SetPos(count);
	}
	f_sfile.Close();
	file.Close();
}

//�ϴ��������ݵ�mysql��������ҵ������Ķ������ݿ����Ѿ����ڣ����ϴ�
void CRefineAndReplaceChineseDlg::CreateTableAndUpload(void)
{
	CString sqlstr,str,tmp,info,only,you;
	CStdioFile f_sfile;
	int count=0,i;
	CFile file("./log\\not_have.txt",CFile::modeWrite|CFile::modeCreate);
	if(!f_sfile.Open("./log\\sql.txt",CFile::modeRead))
	{
		MessageBox("�޷���sql.txt");
		return;
	}
	sqlstr="";
	info="�ϴ����ݵ����ݿ�";
	m_info.SetWindowTextA(info);
	m_progress.SetRange(0,sql_line);
	while(f_sfile.ReadString(str))
	{
		//�Ƚ����������루�ļ�ʹ��UTF8����ģ����Ƕ������õ�asic2������ʹ��asic2->UTF8��
		tmp=str.GetBuffer(str.GetLength());
		char md5key[50];
		MD5String((unsigned char *)tmp.GetString(), tmp.GetLength(), md5key);
		sqlstr="";
		sqlstr+="insert into `test` ";
		sqlstr+="(`chinese` ,`key` ,";
		for(i=0;i<trans_num-1;i++)
			sqlstr+=" `"+trans_Field[i]+"` ,";
		sqlstr+=" `"+trans_Field[trans_num-1]+"` ";
		sqlstr+=")";
		sqlstr+="values (\"";
		sqlstr+=tmp;
		sqlstr+="\",'";
		sqlstr += md5key;
		sqlstr += "', ";
		for(i=0;i<trans_num-1;i++)
			sqlstr+="'',";
		sqlstr+="'');";
		int x=mysql_query(&mydata,sqlstr.GetBuffer(sqlstr.GetLength()));
		string ss=mysql_error(&mydata);
		only=tmp+"\r\n";
		you=only;
		file.Write(you,you.GetLength());
		count++;
		m_progress.SetPos(count);
	}
	file.Close();
	MessageBox("�ϴ�������ϣ�");
}

//��ֹ��������ڳ������е�ʱ��ϣ���û������ť
void CRefineAndReplaceChineseDlg::LockAllBtn(void)
{
	import_btn.EnableWindow(false);
	upload_btn.EnableWindow(false);
	replace_btn.EnableWindow(false);
	doself_btn.EnableWindow(false);
	rpsrc_btn.EnableWindow(false);
}

//�������״̬���ͷ����������İ�ť
void CRefineAndReplaceChineseDlg::ReleaseAllBtn(void)
{
	import_btn.EnableWindow(true);
	upload_btn.EnableWindow(true);
	replace_btn.EnableWindow(true);
	doself_btn.EnableWindow(true);
	rpsrc_btn.EnableWindow(true);
}

//�滻���е����ļ��е�����
void CRefineAndReplaceChineseDlg::OnBnClickedReplaceBtn()
{
	// TODO: Add your control notification handler code here
	LockAllBtn();
	ReplaceQuotes();
	ReleaseAllBtn();
	m_info.SetWindowTextA("");
	m_progress.SetPos(0);
	MessageBox("�滻��ɣ�");
}

//ͨ����������Ŀ���ļ����ҵ������ڵ����ĶΣ����Ҳ������ݿ⣬����ҵ��������ݣ�������滻
void CRefineAndReplaceChineseDlg::ReplaceQuotes(void)
{
	int i,j;
	m_progress.SetRange(0,m_sum);
	for(i=0;i<m_sum;i++)
	{
		CString path,name,info;
		int now_line=0;
		path=m_list.GetItemText(i,2);
		name=m_list.GetItemText(i,1);
		CStdioFile f_sfile;
		CString lcs_FileContent;
		CFile file("./result\\"+name,CFile::modeWrite|CFile::modeCreate);
		char ls_Msg[50000];
		if(!f_sfile.Open(path,CFile::modeRead))
		{
			MessageBox("�����޷��򿪵��ļ���");
			return;
		}
		info="�滻"+name+"��������������";
		m_info.SetWindowTextA(info);
		m_progress.SetPos(i);
		char *output,infile[5000];
		CString sk,ssk,sk2;
		while(f_sfile.ReadString(lcs_FileContent))
		{
			int t=0;
			sk=lcs_FileContent;
			sprintf(ls_Msg,"%s",lcs_FileContent);
			output=GetChinese(ls_Msg);
			now_line++;
			int len=strlen(output);
			for(j=0;j<len;j++)
			{
				if(output[j]=='^')
					output[j]=' ';
			}
			for(j=0;j<len;j++)
			{
				if(output[j]==' '&&output[j+1]=='$')
				{
					infile[t++]='\0';
					CString sqlstr,tmp;
					tmp=infile;
					char md5key[50];
					MD5String((unsigned char *)tmp.GetString(), tmp.GetLength(), md5key);
					sqlstr="SELECT id,english ";
					sqlstr+="FROM  `test` ";
					sqlstr+="WHERE  `key` LIKE  '";
					sqlstr += md5key;
					sqlstr+="'";
					sqlstr+="LIMIT 0 , 30";
					MYSQL_RES *result=NULL;
					if(0==mysql_query(&mydata,sqlstr.GetBuffer(sqlstr.GetLength())))
					{
						result=mysql_store_result(&mydata);
						int fieldcount=mysql_num_fields(result);
						MYSQL_ROW row=NULL;
						row=mysql_fetch_row(result);
						if(row!=NULL)
						{
							if((*row)==NULL)
								continue;
							if(strlen(row[1])>0)
							{
								ssk = "_localization(";
								ssk += row[0];
								ssk += ")";
								sk2 = "\"";
								sk2 += infile;
								sk2 += "\"";
								sk.Replace(sk2, ssk);
							}
						}
					}
					t=0;
					j=j+1;
					continue;
				}
				else
					infile[t++]=output[j];
			}
			sk+="\r\n\0";
			file.Write(sk.GetBuffer(sk.GetLength()),sk.GetLength());
		}
		f_sfile.Close();
		file.Close();
	}
}





//��һ����Ҫ�ֹ�Ū���ļ�
void CRefineAndReplaceChineseDlg::OnBnClickedDoselfBtn()
{
	// TODO: Add your control notification handler code here
	CString str=("TEXT File (*.txt)|*.txt||");
	CString path,name;
	CStdioFile file;
	CFileDialog opendlg(true,NULL,NULL,NULL,str,NULL);
	if(IDOK==opendlg.DoModal())
	{
		doHand.clear();
		path=opendlg.GetPathName();
		selfpath.SetWindowTextA(path);
		if(!file.Open(path,CFile::modeRead))
		{
			MessageBox("�ļ����쳣");
			return;
		}
		while(file.ReadString(name))
		{
			if(doHand[name.GetBuffer(name.GetLength())]==false)
				doHand[name.GetBuffer(name.GetLength())]=true;
		}
		import_btn.EnableWindow(true);
	}
}

//�滻��ԭ�����ļ�
void CRefineAndReplaceChineseDlg::OnBnClickedRpsrcBtn()
{
	// TODO: Add your control notification handler code here
	int i;
	CString name,path;
	m_progress.SetRange(0,m_sum-1);
	for(i=0;i<m_sum;i++)
	{
		name=m_list.GetItemText(i,1);
		path=m_list.GetItemText(i,2);
		m_info.SetWindowTextA("���ڸ���ԭ"+name+"�ļ�");
		m_progress.SetPos(i);
		CopyFile("./result\\"+name,path,false);
	}
	m_info.SetWindowTextA("");
	m_progress.SetPos(0);
	MessageBox("�������!");
}





void CRefineAndReplaceChineseDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	UPDATE_EASYSIZE;
}


void CRefineAndReplaceChineseDlg::OnSizing(UINT fwSide, LPRECT pRect)
{
	CDialogEx::OnSizing(fwSide, pRect);

	// TODO: Add your message handler code here
	EASYSIZE_MINSIZE(min_width,min_hight,fwSide,pRect);
}



void CRefineAndReplaceChineseDlg::create_language_file(CString lanType, char* lan)
{
	CStdioFile file2;
	CString  path, name;
	if (!file2.Open("./result_dir.txt", CFile::modeRead))
	{
		MessageBox("�ļ����쳣");
		return;
	}
	file2.ReadString(name);
	name += "data_language_" + lanType + ".lua";
	CFile file(name, CFile::modeWrite | CFile::modeCreate);

	
	CString sqlstr, sk, tmp;
	sqlstr = "SELECT id, ";
	sqlstr += lan;
	sqlstr += ",chinese FROM  `test` order by id;";
	
	sk = "local _language_";
	sk += lanType;
	sk += " = {\n";

	MYSQL_RES *result = NULL;
	MYSQL_ROW row = NULL;
	
	char ch2[50000];

	if (0 == mysql_query(&mydata, sqlstr))
	{
		result = mysql_store_result(&mydata);
		row = mysql_fetch_row(result);
		while (row)
		{
			m_info.SetWindowTextA(row[0]);
			sk += "[";
			sk += row[0];
			sk += "] = \"";

			if (strlen(row[1])>0){
				tmp = row[1];
			}
			else {
				tmp = row[2];
			}

		//	while (tmp.Find("~") != -1)
		//	{
		//		tmp.Replace("~", "\\");
		//	}

		
			sprintf(ch2, "%s", tmp);
			int len = tmp.GetLength();
			for (int i = 0; i < len - 1; i++)
			{
				if (ch2[i] == '~' && ch2[i+1] == 'n')
				{
					ch2[i] = '\\';
				}
			}

			sk += ch2;
			sk += "\",\n";
			
			row = mysql_fetch_row(result);
		}
	}

	sk += "}\n return _language_";
	sk += lanType;
	sk += "\n";
	file.Write(sk.GetBuffer(sk.GetLength()), sk.GetLength());
	file.Close();

}

/*
void CRefineAndReplaceChineseDlg::create_language_file(CString lanType, char* lan)
{
	CFile file("./sql_error", CFile::modeWrite | CFile::modeCreate);

	CString sqlstr, sk, tmp;
	sqlstr = "SELECT id, word, English FROM  `language` order by id limit 10000;";

	MYSQL_RES *result = NULL;
	MYSQL_ROW row = NULL;

	if (0 == mysql_query(&mydata, sqlstr))
	{
		result = mysql_store_result(&mydata);
		row = mysql_fetch_row(result);
		int i = 0;
		while (row)
		{
			tmp = row[1];
			char md5key[50];
			MD5String((unsigned char *)tmp.GetString(), tmp.GetLength(), md5key);
			sqlstr = "insert into `test` ";
			sqlstr += "(`id`,`key`,`chinese` ,`english`) values ('";
			sqlstr += row[0];
			sqlstr += "', \"";
			sqlstr += md5key;
			sqlstr += "\", \"";
			sqlstr += row[1];
			sqlstr += "\", \"";
			sqlstr += row[2];
			sqlstr += "\");";
			int x = mysql_query(&mydata, sqlstr.GetBuffer(sqlstr.GetLength()));
			string ss = mysql_error(&mydata);
			if (strcmp(ss.c_str(), "") != 0)
			{
				file.Write(sqlstr.GetBuffer(sqlstr.GetLength()), sqlstr.GetLength());
				file.Write("; \n", strlen("; \n"));
			}
			row = mysql_fetch_row(result);
		}
	}
	file.Close();
}*/

void CRefineAndReplaceChineseDlg::OnBnClickedOutBtn()
{
	create_language_file("cn", "chinese");
	create_language_file("en", "english");
	MessageBox("���԰��ļ��������!");
}



