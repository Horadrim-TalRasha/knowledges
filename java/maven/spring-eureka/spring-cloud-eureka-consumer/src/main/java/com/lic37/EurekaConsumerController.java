package com.lic37;

import com.netflix.appinfo.InstanceInfo;
import com.netflix.discovery.EurekaClient;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
//import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.client.RestTemplate;
import org.springframework.boot.web.client.RestTemplateBuilder;

@RestController
public class EurekaConsumerController {
    @Autowired
	EurekaConsumerController() {
        RestTemplateBuilder temporaryBuilder = new RestTemplateBuilder();
		restTemplate = temporaryBuilder.build();
	}

	private RestTemplate restTemplate;

	@Autowired
	private EurekaClient eurekaClient;

    @Value("${configuration.eureka-provider-id}")
    String providerID;

    @RequestMapping("/")
	public String home() {
        InstanceInfo providerInstInfo = eurekaClient.getNextServerFromEureka(providerID, false);
		String homePageUrl = providerInstInfo.getHomePageUrl();
		String response = restTemplate.getForObject(homePageUrl, String.class);
        return response;
	}

}
