package com.lic37.annotation;

import org.springframework.boot.context.properties.ConfigurationProperties;

@ConfigurationProperties(prefix = "hello")
public class AutoConfigurationProperties {
    private static final String Msg = "world";

    private String msg = Msg;

    public String getMsg() {
        return msg;
    }

    public void setMsg(String other) {
        this.msg = other;
    }
}
