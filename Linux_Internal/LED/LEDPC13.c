#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



#define GPIO_EN "/sys/class/gpio/export"
#define GPIO_DIR "/sys/class/gpio/PC13/direction"
#define GPIO_Val "/sys/class/gpio/PC13/value"

int main(){
        int gpio_fd;
        char gpio_buf[30];
        int gpio_num = 77;
        int count = 10;
        gpio_fd = open(GPIO_EN,O_WRONLY);
        if(gpio_fd < 0){
                printf("Unable to Openthe File %s\n",GPIO_EN);
                exit(0);
        }
        //printf("Enable the GPIO\n");
        sprintf(gpio_buf,"%d",gpio_num);
        write(gpio_fd,gpio_buf,strlen(gpio_buf));
        close(gpio_fd);

        //printf("Configuration GPIO direction\n");


        gpio_fd = open(GPIO_DIR,O_WRONLY);
        if(gpio_fd < 0){
                printf("Unable to Openthe File %s\n",GPIO_DIR);
                exit(0);
        }

        write(gpio_fd,"out",3);
        close(gpio_fd);

        //printf("Set the value into GPIO_Val\n);


        gpio_fd = open(GPIO_Val,O_WRONLY);
        if(gpio_fd < 0){
                printf("Unable to Openthe File %s\n",GPIO_Val);
                exit(0);

        }

        //printf("Toggling the GPIO_PIN\n");

        while(count--){
                write(gpio_fd,"0",1);
                sleep(2);
                 write(gpio_fd,"1",1);
                sleep(2);

        }

        close(gpio_fd);
}
