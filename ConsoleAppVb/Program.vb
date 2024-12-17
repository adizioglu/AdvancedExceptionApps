Namespace ConsoleUI
    Class Program
        Shared Sub Main(args As String())

            Dim name As String = ""

            Try
                DifferentMethod()

                Console.Write("What is your name: ")
                name = Console.ReadLine()
                ComplexMethod(name)
                SimpleMethod()
            Catch ex As InvalidOperationException
                Console.WriteLine("You should not be calling these methods.")
                Console.WriteLine(ex.Message)
            Catch ex As NotImplementedException
                Console.WriteLine("You forgot to finish your code!!!!")
            Catch ex As Exception When name.ToLower() = "tim"
                Console.WriteLine("You used Tim's name, didn't you?")
            Catch ex As Exception
                Console.WriteLine(ex)
            Finally
                Console.WriteLine("I always run")
            End Try

            Console.ReadLine()

        End Sub

        Private Shared Sub ComplexMethod(name As String)
            If name.ToLower() = "tim" Then
                Throw New InsufficientMemoryException("Tim is too tall for this method.")
            Else
                Throw New ArgumentException("This person isn't Tim.")
            End If
        End Sub

        Private Shared Sub DifferentMethod()
            Console.WriteLine("This is the different method working properly.")
        End Sub

        Private Shared Sub SimpleMethod()
            Throw New InvalidOperationException("You should not be calling the SimpleMethod")
        End Sub
    End Class
End Namespace
