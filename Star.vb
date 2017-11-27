left1 = Int(Rnd * 7000) + 1000
left2 = Int(Rnd * 7000) + 1000
left3 = Int(Rnd * 7000) + 1000
top1 = Int(Rnd * 5000) + 100
top2 = Int(Rnd * 5000) + 100
top3 = Int(Rnd * 5000) + 100
Image2.Left = left1
Image3.Left = left2
Image4.Left = left3
Image2.Top = top1
Image3.Top = top2
Image4.Top = top3
w = 0
score = 0
Label7.Caption = Str$(score)
End Sub

Private Sub Image7_Click()
Label5.Visible = False
End Sub
 

Private Sub Timer1_Timer()

MMControl1.Command = "close"

If Image1.Left < 15000 And Image1.Top < 9000 Then

v = Val(Text1.Text)
a = Val(Text2.Text)
t = t + 1

' To use the formula vertical displacement=vsina- (1/2)gt^2 and horizontal displacement=vcosa*t
'So that it follows a parabolic trajectory

y = v * Sin(a * 3.141592654 / 180) * t - 4.9 * (t ^ 2)
x = v * Cos(a * 3.141592654 / 180) * t
Image1.Move Image1.Left + x, Image1.Top - y
If Image4.Visible = True And (Image1.Left < left3 + 240 And Image1.Left > left3 - 240) And (Image1.Top < top3 + 240 And Image1.Top > top3 - 240) Then
i = 2

Get the Starwar Complete Code