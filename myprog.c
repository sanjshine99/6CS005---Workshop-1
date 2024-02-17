/*Question 1*/
// #include <stdio.h>
// #include <stdlib.h>

// int main(int argc, char *argv[]) {
//     if (argc != 3) {
//         printf("Usage: %s <name> <age>\n", argv[0]);
//         return 1;
//     }

//     char *name = argv[1];
//     int age = atoi(argv[2]);

//     printf("Hello %s, you are %d years old.\n", name, age);

//     return 0;
// }

/*Question 2*/
// #include <stdio.h>

// int main() {
//     char name[100];
//     int age;

//     printf("Enter your name: ");
//     scanf("%s", name);

//     printf("Enter your age: ");
//     scanf("%d", &age);

//     printf("Hello %s, you are %d years old.\n", name, age);

//     return 0;
// }

/*Question 3*/
// #include <stdio.h>

// int main() {
//     for (int n = 1; n <= 100; n++) {
//         if (n % 2 == 0) {
//             printf("Bish");
//         }
//         if (n % 3 == 0) {
//             printf("Bash");
//         }
//         if (n % 5 == 0) {
//             printf("Bosh");
//         }
//         if (n % 2 != 0 && n % 3 != 0 && n % 5 != 0) {
//             printf("%d", n);
//         }
//         printf("\n");
//     }
//     return 0;
// }

/*Question 4*/
// #include <stdio.h>

// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int main() {
//     int a = 3;
//     int b = 4;

//     printf("Before swapping: a is %d and b is %d\n", a, b);

//     swap(&a, &b);

//     printf("After swapping: a is now %d and b is now %d\n", a, b);

//     return 0;
// }

/*Question 5*/
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// int main() {
//     int size;

//     do {
//         printf("Enter the size of the array (between 1 and 50): ");
//         scanf("%d", &size);
//     } while (size < 1 || size > 50);

//     int *numbers = (int *)malloc(size * sizeof(int));

//     if (numbers == NULL) {
//         printf("Memory allocation failed.\n");
//         return 1;
//     }

//     srand(time(NULL));

//     for (int i = 0; i < size; i++) {
//         numbers[i] = rand();
//         printf("%d is %d\n", i, numbers[i]);
//     }

//     free(numbers);

//     return 0;
// }

/*Question 6*/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *threadA(void *p)
{
  for (int i = 0; i < 10; i++)
  {
    printf("Thread ID %ld: i=%d\n", pthread_self(), i);
    usleep(1000);
  }
}
void *threadB(void *p)
{
  for (int i = 0; i < 10; i++)
  {
    printf("Thread ID %ld: i=%d\n", pthread_self(), i);
    usleep(1000);
  }
}
void main()
{
  pthread_t thrID1, thrID2;
  pthread_create(&thrID1, NULL, threadA, NULL);
  pthread_create(&thrID2, NULL, threadB, NULL);
  pthread_join(thrID1, NULL);
  pthread_join(thrID2, NULL);
}
