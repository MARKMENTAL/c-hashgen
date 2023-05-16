# Introduction:
One-time password (OTP) systems are commonly used for two-factor authentication (2FA), where a user provides two forms of authentication to access a system or service. This C program can serve as a simple demonstration of how an OTP system works and how it can be implemented using the OpenSSL library in C.

# Functionality:
The program accepts a hash type (256 or 512) and a seed string as input from the user. It then generates a hash value based on the selected hash type using the OpenSSL SHA256 or SHA512 function. The hash value is converted to a hexadecimal string, and a 6-digit code is extracted from the string based on a counter that is incremented by a random value each time the loop runs.

The program continuously generates a new code every 30 seconds and prints the current time, hash value, and code to the console. It also writes the same information to a file named "output.txt" in the current directory.

# Educational Value:
As a proof-of-concept or educational tool, this program demonstrates the basic functionality of an OTP system by showing how a seed string can be used to generate a hash value, and how a 6-digit code can be extracted from the hash value to provide the second factor of authentication. It also shows how the OpenSSL library can be used to perform cryptographic functions in C, such as generating hash values.

# Limitations:
It's important to note that this program doesn't provide any additional security features such as rate limiting, session management, or user authentication, which are typically included in production-grade OTP backend applications. Therefore, this program should be used for educational or experimental purposes only and should not be used as a production-grade OTP system.

# Conclusion:
This program can be a useful tool for learning about OTP systems and how they can be implemented using the OpenSSL library in C. However, it's important to keep in mind the limitations of this program and to use it for educational or experimental purposes only.

# Compilation Instructions:
To compile the hashgen program, follow these steps:

Open a terminal window.

Navigate to the directory where the hashgen.c file is located using the cd command.

Type the following command to compile the program:

```
gcc -o hashgen hashgen.c -lcrypto
```

Press the Enter key to execute the command.

If there are no errors, the hashgen program will be compiled and an executable file named hashgen will be created in the same directory as the source code.