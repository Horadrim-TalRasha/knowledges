package com.lic37.annotation;

import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.beans.factory.annotation.Autowired;

@RestController
public class AutoConfigurationAnnoController {

    @Autowired
    private AutoConfigure configure;

    @RequestMapping("/autoconfig")
    public String autoConfig() {
        return configure.sayHello();
    }
}
