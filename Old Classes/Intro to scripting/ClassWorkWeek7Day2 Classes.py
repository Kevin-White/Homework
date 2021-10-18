class Student:
    def __init__(self, ID=0, first_name = "Nobody"):
        self.ID=ID
        self.first_name=first_name
        self.age=18

    def print_name(self):
        print("My name is", self.first_name)

    def print_full_name(self, last_name):
        print("My name is {} {}".format(self.first_name, last_name))

    @staticmethod
    def static_example():
        print("this is a static method, no self pointer")

    @staticmethod
    def static_example_2(last_name):
        print("This is your last name {}".format(last_name))


def main():
    stu = Student(ID=888, first_name="Kevin")
    stu.print_name()
    stu.print_full_name("White")
    stu = Student()
    stu.print_name()
    Student.static_example_2("White")
    stu.static_example()




if __name__ == '__main__':
    main()