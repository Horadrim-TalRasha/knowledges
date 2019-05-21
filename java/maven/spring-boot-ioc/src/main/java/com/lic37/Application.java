package com.lic37;

import org.springframework.boot.*;
import org.springframework.boot.autoconfigure.*;
import org.springframework.web.bind.annotation.*;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Bean;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;

import org.springframework.stereotype.Component;
import org.springframework.stereotype.Controller;

import org.springframework.context.annotation.ImportSelector;
import org.springframework.context.annotation.Import;
import org.springframework.core.type.AnnotationMetadata;


@SpringBootApplication
@RestController
@EnableAutoConfiguration
public class Application {
    @RequestMapping("/")
    public String home() {
        return "Hello Spring Boot, IOC!";
    }
/**
    @RequestMapping("/serviceanno")
    public String serviceAnno()
    {
        return annoIntegrator.ServiceAnnoInterface();
    }
**/
    public static void main(String[] args) {
        ApplicationContext springCtx = SpringApplication.run(Application.class, args);
        /*
        String[] beanNames = springCtx.getBeanDefinitionNames();
        ShiroConfig c = springCtx.getBean(ShiroConfig.class);
        System.out.println("Bean ran:" + c.foo());
        for(String beanName : beanNames)
        {
            System.out.println("Bean name: " + beanName);
        }
        */
    }
}
