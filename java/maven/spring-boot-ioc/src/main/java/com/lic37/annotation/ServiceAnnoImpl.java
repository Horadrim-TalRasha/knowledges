package com.lic37.annotation;

import org.springframework.stereotype.Service;

@Service
class ServiceAnnoImpl implements ServiceAnnoInterface {
    @Override
    public String InterfaceA() {
        return "This is InterfaceA called in ServiceAnnoImpl and implements ServiceAnnoInterface";
    }

    @Override
    public String InterfaceB() {
        return "This is InterfaceB called in ServiceAnnoImpl and implements ServiceAnnoInterface";
    }



}
