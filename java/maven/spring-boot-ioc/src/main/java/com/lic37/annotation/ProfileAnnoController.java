package com.lic37.annotation;

import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.beans.factory.annotation.Autowired;

@RestController
class ProfileAnnoController {
    @Autowired
    public ProfileAnnoController() {

    }

    @Autowired
    ProfileAnno myAnno;

    @RequestMapping("/profileanno")
    String ProfileHome() {
        return myAnno.take();
    }
}
