#include "pch.h"
#include "CLine.h"

IMPLEMENT_SERIAL(CLine, CObject, 1)

void CLine::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		ar << m_From << m_To << m_Size << m_Col;
	}
	else
	{	// loading code
		ar >> m_From >> m_To >> m_Size >> m_Col;
	}
}
