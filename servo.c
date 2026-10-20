#include <stdio.h>
#include <stdbool.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/ledc.h"

// Definição dos 8 pinos dos botões
#define BT1_PIN 4
#define BT2_PIN 16
#define BT3_PIN 17
#define BT4_PIN 21
#define BT5_PIN 23
#define BT6_PIN 25
#define BT7_PIN 26
#define BT8_PIN 27

#define SERVO_PIN 22

void init_test_hardware(void) {
    // Configura os 8 pinos como entrada com Pull-Up interno
    int pins[] = {BT1_PIN, BT2_PIN, BT3_PIN, BT4_PIN, BT5_PIN, BT6_PIN, BT7_PIN, BT8_PIN};
    for (int i = 0; i < 8; i++) {
        gpio_reset_pin(pins[i]);
        gpio_set_direction(pins[i], GPIO_MODE_INPUT);
        gpio_pullup_en(pins[i]);
    }
}

void app_main(void) {
    init_test_hardware();
    
    printf("\n=== SISTEMA PRONTO: TESTE DOS 8 BOTÕES ===\n");
    printf("Pressione qualquer botão para ver a leitura no monitor.\n");

    while (1) {
        // Lê o estado de cada botão (lembrando que com pull-up, pressionado = 0)
        bool bt1 = (gpio_get_level(BT1_PIN) == 0);
        bool bt2 = (gpio_get_level(BT2_PIN) == 0);
        bool bt3 = (gpio_get_level(BT3_PIN) == 0);
        bool bt4 = (gpio_get_level(BT4_PIN) == 0);
        bool bt5 = (gpio_get_level(BT5_PIN) == 0);
        bool bt6 = (gpio_get_level(BT6_PIN) == 0);
        bool bt7 = (gpio_get_level(BT7_PIN) == 0);
        bool bt8 = (gpio_get_level(BT8_PIN) == 0);

        if (bt1) printf("Botão 1 acionado (Esquerda Cima)!\n");
        if (bt2) printf("Botão 2 acionado (Meio Cima)!\n");
        if (bt3) printf("Botão 3 acionado (Direita Cima)!\n");
        if (bt4) printf("Botão 4 acionado (Esquerda Meio)!\n");
        if (bt5) printf("Botão 5 acionado (Direita Meio)!\n");
        if (bt6) printf("Botão 6 acionado (Esquerda Baixo)!\n");
        if (bt7) printf("Botão 7 acionado (Meio Baixo)!\n");
        if (bt8) printf("Botão 8 acionado (Direita Baixo)!\n");

        vTaskDelay(pdMS_TO_TICKS(200)); // Pequeno atraso para evitar excesso de spam no console
    }
}
