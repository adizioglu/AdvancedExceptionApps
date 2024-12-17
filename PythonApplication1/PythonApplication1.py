class Program:
    @staticmethod
    def main():
        name = ""

        try:
            Program.different_method()

            name = input("What is your name: ")
            Program.complex_method(name)
            Program.simple_method()
        except InvalidOperationException as ex:
            print("You should not be calling these methods.")
            print(ex)
        except NotImplementedError:
            print("You forgot to finish your code!!!!")
        except Exception as ex:
            if name.lower() == "tim":
                print("You used Tim's name, didn't you?")
            else:
                print(ex)
        finally:
            print("I always run")

    @staticmethod
    def complex_method(name):
        if name.lower() == "tim":
            raise MemoryError("Tim is too tall for this method.")
        else:
            raise ValueError("This person isn't Tim.")

    @staticmethod
    def different_method():
        print("This is the different method working properly.")

    @staticmethod
    def simple_method():
        raise InvalidOperationException("You should not be calling the SimpleMethod")


class InvalidOperationException(Exception):
    pass


if __name__ == "__main__":
    Program.main()

