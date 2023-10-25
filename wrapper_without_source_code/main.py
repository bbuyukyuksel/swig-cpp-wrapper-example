import myclass

if __name__ == '__main__':
    cls = myclass.MyClass()

    date01 = myclass.Date(2023, 10, 5)
    print(cls.printDate(date01))

    date02 = myclass.Date(2020, 5, 10)
    print(cls.printDate(date02))

