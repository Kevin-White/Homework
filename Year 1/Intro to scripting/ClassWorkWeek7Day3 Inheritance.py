class Person:
    def __init__(self, fname, lname):
        self.firstname = fname
        self.lastname = lname

    def print_name(self):
        print(self.firstname, self.lastname)


class Student(Person):
    def __init__(self, fname, lname):
        super().__init__(fname, lname)
        self.id = 88

    def do_homework(self):
        print("{name} is doing homework {name}'s ID is: {id}".format(name = self.firstname, id = self.id))
        
class Professor(Person):
    def __init__(self, fname, lname, id=90):
        self.id = id
        super().__init__(fname, lname)


def main():
    student = Student("Kevin", "White")
    student.print_name()
    student.do_homework()




if __name__ == '__main__':
    main()