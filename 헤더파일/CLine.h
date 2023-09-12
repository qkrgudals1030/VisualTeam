#pragma once
#include <afx.h>
class CLine :
    public CObject
{
    DECLARE_SERIAL(CLine)
    CPoint m_From;
    CPoint m_To; 
    int m_Size;
    COLORREF m_Col;
public:
    CLine(){} //디폴트 생성자
    CLine(CPoint From, CPoint To, int Size, COLORREF Col) {
        m_From = From;
        m_To = To;
        m_Size = Size;
        m_Col = Col;

    }
    void Draw(CDC* pDC) {
        CPen pen(PS_SOLID, m_Size, m_Col);
        pDC->SelectObject(&pen);
        pDC->MoveTo(m_From);
        pDC->LineTo(m_To);
    }
    virtual void Serialize(CArchive& ar);
};

