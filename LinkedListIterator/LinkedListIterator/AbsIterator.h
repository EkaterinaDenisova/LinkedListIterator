#pragma once
//author: �������� ���������

template <typename T>
// ����������� ����� ���������
class AbsIterator
{
    // �������� �������� �� ��������� �������
    virtual void  operator++() const {};
    // �������� ��������� ������ �� ��������
    virtual T& operator*() const = 0;
    // ��������� ���������
    virtual bool operator==(const AbsIterator& o) const = 0;
    virtual bool operator!=(const AbsIterator& o) const = 0;

};

