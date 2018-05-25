
// RefineAndReplaceChineseDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "EasySize.h"
#include "MD5.h"


// CRefineAndReplaceChineseDlg �Ի���
class CRefineAndReplaceChineseDlg : public CDialogEx
{
// ����
public:
	DECLARE_EASYSIZE
	CRefineAndReplaceChineseDlg(CWnd* pParent = NULL);	// ��׼���캯��
// �Ի�������
	enum { IDD = IDD_REFINEANDREPLACECHINESE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedImportBtn();
	CListCtrl m_list;
	CButton import_btn;
	CButton upload_btn;
	CButton replace_btn;
	int m_sum;
	MYSQL mydata;
	void initMySql(void);
	afx_msg void OnBnClickedUploadBtn();
	void GetQuotes(void);
	void GetSqlFile(void);
	void create_language_file(CString, char*);
	void DoMap(void);
	std::map<std::string,bool>rep;
	std::map<std::string,bool>doHand;
	void CreateTableAndUpload(void);
	void LockAllBtn(void);
	void ReleaseAllBtn(void);
	afx_msg void OnBnClickedReplaceBtn();
	void ReplaceQuotes(void);
	void CopyTemp(void);
	CStatic m_info;
	CProgressCtrl m_progress;
	int logx_line;
	int logy_line;
	int log_line;
	int sql_line;
	void ScanFile(CString Dir);
	CButton doself_btn;
	CStatic selfpath;
	afx_msg void OnBnClickedDoselfBtn();
	CButton rpsrc_btn;
	afx_msg void OnBnClickedRpsrcBtn();
	//CComboBox selectlanguage;
	int now_trans;
	afx_msg void OnCbnSelchangeCombo1();
	CString trans_Field[20];
	int trans_num;
	int min_width;
	int min_hight;
	string m_sqlip,m_sqlname,m_sqlpassword,m_sqltable;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	afx_msg void OnBnClickedOutBtn();
};
