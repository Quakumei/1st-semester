Attribute VB_Name = "Module1"
Function ���������(��������������, ����������, ������)
If ���������� < 100 Then
������������������ = �������������� * ����������
Else
    If ���������� <= 200 Then
    ������������������ = �������������� * ���������� * 0.93
    Else
        If ���������� <= 300 Then
        ������������������ = �������������� * ���������� * 0.85
        Else
        ������������������ = �������������� * ���������� * 0.85
        End If
    End If
End If
If ������ = 0 Then
    ��������� = ������������������
    Else
    ��������� = ������������������ * 0.95
End If
End Function