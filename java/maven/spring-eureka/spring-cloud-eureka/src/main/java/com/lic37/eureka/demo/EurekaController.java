package com.lic37.eureka.demo;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.stereotype.Controller;

@Controller
@RestController
class EurekaController {

    @RequestMapping("/")
    public String home() {
        return "Hello Eureka";
    }

    @RequestMapping("/health")
    public String health() {
        return "I'm Eureka, and I'm health";
    }
}
