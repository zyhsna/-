# _*_ coding:UTF-8 _*_
# 开发人员：zyh
# 开发时间：2019/10/28 22:54
# 文件名：some strange and random code.py
# 开发工具：PyCharm

information = []


class person_information(object):
    def __init__(self, name, age, his_type):
        self.name = name
        self.age = age
        self.his_type = his_type

    def __repr__(self):
        return 'name：%r  age:%r  type %r' % (self.name, self.age, self.his_type)

    def modify(self):
        self.name = input("change his name")
        self.age = int(input("change his age"))
        self.his_type = input("change his type")


def add():
    name = input("please input your friend's name")
    age = int(input("please input his age"))
    his_type = input("please input his type (A or B or C)")
    new_person_information = person_information(name, age, his_type)
    information.append(new_person_information)


def traverse():
    for person in information[:]:
        print(person)


def search():
    sign = 0
    target = input("which one do you like to find")
    for person in information:
        if person.name == target:
            print(person)
            sign = 1
    if sign == 1:
        print("we have already found it")
    elif sign == 0:
        print("we can't find it")


def summary():
    sign = 0
    already_output = 0
    target_group = input("which type of people do you like to find A or B or C")
    for person in information[:]:
        if person.his_type.lower() == target_group.lower():
            print(person)
            sign = 1
            already_output = 1
        if person.his_type.upper() == target_group.upper() and already_output == 0:
            print(person)
            sign = 1

    if sign == 1:
        print("we have found them")
    else:
        print("there's no such type of people")


def modify():
    target_person = input("which one do you like to change")
    for people in information:
        if target_person == people.name:
            people.modify()
            break
    traverse()


def sorted_output():
    for pre_person in range(len(information)):
        for cur_person in range(pre_person, len(information)):
            if information[pre_person].name > information[cur_person].name:
                temp = information[pre_person]
                information[pre_person] = information[cur_person]
                information[cur_person] = temp
    traverse()


def delete():
    target_person = input("which one do you like to del")
    for pre_person in range(len(information)):
        if information[pre_person].name == target_person:
            information.pop(pre_person)
            break
    traverse()


if __name__ == '__main__':
    q = 1
    while q:
        print("add  new information,put 1")
        print("see all information , put 2")
        print("find a person,put 3")
        print("find one type of people,put 4")
        print("modify one's information,put 5")
        print("see the sorted information,put 6")
        print("delete one's information,put 7")
        choice = int(input("please make your choice"))
        if choice == 1:
            add()
        elif choice == 2:
            traverse()
        elif choice == 3:
            search()
        elif choice == 4:
            summary()
        elif choice == 5:
            modify()
        elif choice == 6:
            sorted_output()
        elif choice == 7:
            delete()
        q = int(input("would you want to continue to use?"))
