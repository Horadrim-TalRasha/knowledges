package com.lic37.annotation;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

@Controller
public class ServiceAnnoController {
    @Autowired
    public ServiceAnnoController() {

    }

    @Autowired
    private ServiceAnnoInterface iServiceAnnoInterface;

    @RequestMapping("/serviceanno")
    @ResponseBody
    public String serviceAnno()
    {
        return iServiceAnnoInterface.InterfaceA() + "\n" +
            iServiceAnnoInterface.InterfaceB();
    }
}
