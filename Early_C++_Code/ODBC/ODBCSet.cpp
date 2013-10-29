
// ODBCSet.cpp : CODBCSet 类的实现
//

#include "stdafx.h"
#include "ODBC.h"
#include "ODBCSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CODBCSet 实现

// 代码生成在 2012年7月7日 星期六, 20:48

IMPLEMENT_DYNAMIC(CODBCSet, CRecordset)

CODBCSet::CODBCSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_name = L"";
	m_age = 0;
	m_empid = 0;
	m_nFields = 4;
	m_nDefaultType = dynaset;
}
//#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CODBCSet::GetDefaultConnect()
{
	return _T("DSN=sql2008test;Description=test;UID=sa;PWD=aixiteluli16;APP=Microsoft\x00ae Visual Studio\x00ae 2010;WSID=LIU-PC;DATABASE=test;Network=DBMSSOCN;Address=liu-PC");
}

CString CODBCSet::GetDefaultSQL()
{
	return _T("[dbo].[student]");
}

void CODBCSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Long(pFX, _T("[age]"), m_age);
	RFX_Long(pFX, _T("[empid]"), m_empid);

}
/////////////////////////////////////////////////////////////////////////////
// CODBCSet 诊断

#ifdef _DEBUG
void CODBCSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CODBCSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

