import matplotlib.pyplot as plt

class NoiTiep:
	def __init__(self,x1,y1,x2,y2):
		self.x1 = x1
		self.y1 = y1
		self.x2 = x2
		self.y2 = y2
	def Draw(self):
		line = plt.Line2D((self.x1,self.x2), (self.y1,self.y2), lw = 2.5)
		plt.gca().add_line(line)

class SongSong:
	def __init__(self,x1,y1,x2,y2,x3,y3,x4,y4):
		self.x1 = x1
		self.y1 = y1
		self.x2 = x2
		self.y2 = y2
		self.x3 = x3
		self.y3 = y3
		self.x4 = x4
		self.y4 = y4
	def DrawLine1(self):
		line1 = plt.Line2D((self.x1,self.x2), (self.y1,self.y2), lw = 5)
		plt.gca().add_line(line1)
	def DrawLine2(self):
		line2 = plt.Line2D((self.x3,self.x4), (self.y3,self.y4), lw = 5)
		plt.gca().add_line(line2)
			
class DienTro:
	def __init__(self, x, y, w, h):
		self.x = x
		self.y = y
		self.w = w
		self.h = h
	def Draw(self):
		rectangle = plt.Rectangle ((self.x,self.y), self.w, self.h, fc='r')
		plt.gca().add_patch(rectangle)

deltaX = 1
deltaY = 1
x_anchor = 0
y_anchor = 0
plt.axes()
print("Nhap input. Co khoang trang giua cac ky tu va dau ngoac. Vi du: R3 // ( R1 nt R2 )")
arrDes = input()
# R1 nt R2 nt R3 nt R4 nt R5
# R1 // R2 // R3 // R4 // R5
# R1 // (R2 nt R3)
# R1 nt R2 nt R3 nt (R4//R5)
i = 0
for word in arrDes.split():
	if (word[0] != '('):
		if (word[0] == 'R'):
			R = DienTro (x_anchor, y_anchor, 2, 1)
			R.Draw()
		if (word[0] == 'n'):
			x_anchor += R.w + deltaX
			LineNT = NoiTiep(R.x + R.w,R.y + R.h/2, R.x + R.w + deltaX, R.y + R.h/2)
			LineNT.Draw()
		if (word[0] == '/'):
			y_anchor += R.h + deltaY
			LineSS = SongSong(R.x, R.y + R.h/2, R.x, R.y + 1.5*R.h + deltaY, R.x + R.w, R.y + R.h/2, R.x + R.w, R.y + 1.5*R.h + deltaY)
			LineSS.DrawLine1()
			LineSS.DrawLine2()
	else:
		open_bracket = arrDes.find('(', i)
		close_bracket = arrDes.find(')', i)
		for words in arrDes[open_bracket:close_bracket+1].split():
			#print(words)
			if (words[0] == 'R'):
				R = DienTro (x_anchor, y_anchor, 1/arrDes[open_bracket:close_bracket+1].count('R'), 1)
				R.Draw()
			if (words[0] == 'n'):
				x_anchor += R.w + deltaX
				LineNT = NoiTiep(R.x + R.w,R.y + R.h/2, R.x + R.w + deltaX, R.y + R.h/2)
				LineNT.Draw()
			if (words[0] == '/'):
				y_anchor += R.h + deltaY
				LineSS = SongSong(R.x, R.y + R.h/2, R.x, R.y + 1.5*R.h + deltaY, R.x + R.w, R.y + R.h/2, R.x + R.w, R.y + 1.5*R.h + deltaY)
				LineSS.DrawLine1()
				LineSS.DrawLine2()
		i = close_bracket
	i += 1
	if (i == len(arrDes)):
		break
plt.axis('scaled')
plt.show()


