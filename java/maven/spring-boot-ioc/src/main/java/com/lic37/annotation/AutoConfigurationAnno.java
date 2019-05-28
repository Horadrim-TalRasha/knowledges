package com.lic37.annotation;

import org.springframework.context.annotation.Configuration;
import org.springframework.boot.context.properties.EnableConfigurationProperties;
import org.springframework.boot.autoconfigure.condition.ConditionalOnClass;
import org.springframework.boot.autoconfigure.condition.ConditionalOnProperty;
import org.springframework.boot.autoconfigure.condition.ConditionalOnMissingBean;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;

@Configuration
/**
 * To bind the properties defined in AutoConfigurationProperties
 * and specified in application.properties on current bean
 */
@EnableConfigurationProperties(AutoConfigurationProperties.class)
@ConditionalOnClass(AutoConfigure.class)
/**
 * To control the bean will be inserted or not through redefined
 * properties, also you can define multiple properties as following.
 * @ConditionalOnProperty(prefix = "parentName", name = {"sonName", "flag"}, havingValue = "123",matchIfMissing = true)
 */
@ConditionalOnProperty(prefix = "hello", value = "enabled", matchIfMissing = false, havingValue = "false")
public class AutoConfigurationAnno {

    @Autowired
    private AutoConfigurationProperties prop;

    @Bean
    @ConditionalOnMissingBean(AutoConfigure.class)
    public AutoConfigure autoConfigure() {
        AutoConfigure autoConfig = new AutoConfigure();
        autoConfig.setMsg(prop.getMsg());
        return autoConfig;
    }

}
