# # a simple parser for python. use get_number() and get_word() to read
# def parser():
#     while 1:
#         data = list(input().split(' '))
#         for number in data:
#             if len(number) > 0:
#                 yield(number)   

# input_parser = parser()

# def get_word():
#     global input_parser
#     return next(input_parser)

# def get_number():
#     data = get_word()
#     try:
#         return int(data)
#     except ValueError:
#         return float(data)

# # numpy and scipy are available for use
# import numpy
# import scipy

# a = get_number()
# b = get_number()

# res = a + b
# print(res)
# while True:
#     z=input()
#     if not(z):
#         break
#     #print(z)
#     for i in range(len(z)):
#         if 97<=ord(z[i])<=108 or 65<=ord(z[i])<=76:
#             print(chr(ord(z[i])+14),end="")
#         elif 109<=ord(z[i])<=122 or 77<=ord(z[i])<=90:
#             print(chr(ord(z[i])-12),end="")
#         else:
#             print(z[i],end="")
#     print("")
z=input()
#print(z)
for i in range(len(z)):
    if 97<=ord(z[i])<=108 or 65<=ord(z[i])<=76:
        print(chr(ord(z[i])+14),end="")
    elif 109<=ord(z[i])<=122 or 77<=ord(z[i])<=90:
        print(chr(ord(z[i])-12),end="")
    else:
        print(z[i],end="")