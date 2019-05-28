package com.lic37.annotation;


class AutoConfigure {
    private String msg;

    public String sayHello() {
        return "hello " + msg;
    }

    public String getMsg() {
        return msg;
    }

    public void setMsg(String other) {
        this.msg = other;
    }
}
