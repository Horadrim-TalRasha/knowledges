package com.lic37.annotation;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component
public class ProfileAnno {

    @Autowired
    private ProfileInterface myInterface;

    public String take() {
        return myInterface.take();
    }
}
