Private Sub Command1_Click()

'To start the timer

    Timer1.Enabled = True
    x = 0

End Sub

Private Sub Timer1_Timer()

    x = x + 10
    Dim a, i As Integer
    Randomize Timer

    For i = 0 To 8

    ' To generate random integers 0,1 and 2
    a = Int(Rnd * 3)
    Shape1(i).Shape = a
    If a = 0 Then

    Shape1(i).FillColor = vbRed
    ElseIf a = 1 Then
    Shape1(i).FillColor = vbGreen
    Else
    Shape1(i).FillColor = vbBlue
    End If
    Next i

    'To stop the timer
    If x > 500 Then
    Timer1.Enabled = False
    End If
     

End Sub