# 3) 
head -n b+a filename | tail -n a
# Вывести a строк начиная с b'ой строки
# head - выводит верхнюю часть файла - b+a строк
# начиная с начала файла
# tail же выводит последние a строк уже обрубленного файла
# по сути отсекая b строк с начала
# после чего остаётся нужный фрагмент
#