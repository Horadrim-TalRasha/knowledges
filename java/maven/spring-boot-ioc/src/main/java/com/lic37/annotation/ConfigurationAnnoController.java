package com.lic37.annotation;

import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;

@RestController
class ConfigurationAnnoController {

    @Autowired
	@Qualifier("ConfigAnnoStr")
    String ConfigAnnoStr;

    @Autowired
	@Qualifier("ConfigAnnoStr2")
    String ConfigAnnoStr2;

    @RequestMapping("/configanno")
    public String ConfigAnno() {
        return ConfigAnnoStr + " " + ConfigAnnoStr2;
    }
}
