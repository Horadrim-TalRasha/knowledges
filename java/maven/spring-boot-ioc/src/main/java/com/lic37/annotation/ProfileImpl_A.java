package com.lic37.annotation;


import org.springframework.context.annotation.Profile;
import org.springframework.stereotype.Component;

@Component
@Profile(value = "pro")
public class ProfileImpl_A implements ProfileInterface {
    @Override
    public String take() {
        return "take - called in ProfileImpl_A";
    }
}
