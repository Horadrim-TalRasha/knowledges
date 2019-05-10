package hello;

import org.springframework.boot.*;
import org.springframework.boot.autoconfigure.*;
import org.springframework.web.bind.annotation.*;

/**
 * import org.springframework.boot.SpringApplication;  
 * import org.springframework.boot.autoconfigure.SpringBootApplication;  
 * import org.springframework.web.bind.annotation.RequestMapping;  
 * import org.springframework.web.bind.annotation.RestController;
 */

/**
 * Entry of main application
 */

@SpringBootApplication
@RestController
@EnableAutoConfiguration

public class Application {

    @RequestMapping("/")
    public String home() {
        return "Hello Spring Boot, Docker and CloudComb!";
    }


    public static void main(String[] args) {
        SpringApplication.run(Application.class, args);
    }

}
