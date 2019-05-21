package com.lic37.annotation;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class ConfigurationAnno {
    public ConfigurationAnno() {
        System.out.println("It's constructor");
    }
    @Bean(name="ConfigAnnoStr")
    public String description() {
        System.out.println("be called here");
        return "This is description";
    }

    @Bean(name="ConfigAnnoStr2")
    public String description2() {
        System.out.println("be called here 2");
        return "This is description 2";
    }
}
