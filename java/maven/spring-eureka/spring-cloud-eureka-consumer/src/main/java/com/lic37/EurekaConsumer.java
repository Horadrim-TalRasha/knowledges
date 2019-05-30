package com.lic37;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.netflix.eureka.EnableEurekaClient;
import org.springframework.beans.factory.annotation.Value;

@SpringBootApplication
@EnableEurekaClient
public class EurekaConsumer {

    public static void main(String[] args) {
        SpringApplication.run(EurekaConsumer.class, args);
	}
}
