# Abstract Base Class (ABC) defines methods that must be implemented by its subclasses
# ensuring that the subclasses follow a consistent structure.
from abc import ABC, abstractmethod

# Product classes:
# 1. The BASE:
class Course(ABC):  # this is the PRODUCT INTERFACE
    @abstractmethod
    def essential(self):
        pass

# 2. The Concrete Products:
class TechCourse(Course):
    def essential(self):
        return "LAPTOP"

class FinCourse(Course):
    def essential(self):
        return "FINANCE SHEET"


# The CREATOR class (where the CLIENT interacts with)
class CourseMan(ABC):
    @abstractmethod
    def assignCourse(self): # This is the Factory Method
        pass

    def handEssential(self):
        course = self.assignCourse()    # Course type
        print(course.essential())

# the Factories: each of these will return their equivalent concrete product with their parent (Interface they inherited from)
# Factories only responsibility is to creating (instantiated object)
# By returning the object typed Interface, later when Client change the factory, it won't create duplicated code
class TechCourseFactory(CourseMan):
    def assignCourse(self) -> Course:
        course = TechCourse()
        return course
    
class FinCourseFactory(CourseMan):
    def assignCourse(self) -> Course:
        course = FinCourse()
        return course
    

def main():
    # Now I'm a client, I dont need to know the process of creating course
    # I only care about what I need for my chosen course
    courseman = TechCourseFactory()
    courseman.handEssential()   # print laptop
    # Client changed their mind
    courseman = FinCourseFactory()
    courseman.handEssential()   # now print sheet


if __name__ == "__main__":
    main()