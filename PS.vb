Dim password As Integer

Dim crackpass As Integer

Private Sub Command1_Click()

Timer1.Enabled = True

End Sub

Private Sub Form_Load()

password = 123

End Sub

Private Sub Timer1_Timer()

crackpass = Int(Rnd * 100) + 100

If crackpass = password Then

Timer1.Enabled = False

Text1.Text = crackpass

Label1.Visible = True

Label1.Caption = "Password Cracked!Login Successful!"

Else

Text1.Text = crackpass

Label1.Visible = True

Label1.Caption = "Please wait..."

End If

End Sub