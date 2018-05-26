/** ####  PROJETO 2 ###################################################
**
**     Filename  : Pong2Player.ino
**     Project   : Projeto_02 - LAB. DE APLICA. COM MICROCOMPUTADORES
**     Professor : André Cavalcante
**     Processor : Atmega328P
**     Version   : 1.00
**     Compiler  : Arduino IDE
**     Date/Time : 24/05/2018, 09:24
**     Aluno     : Gabriel Borralho
**     Última Mod: 20/05/2018
**
** ###################################################################*/

//#### VARIÁVEIS GLOBAIS ##############################################
bool BolaVaiParaPlayer2 = true;
bool EntradaPermitida = true;

const int player1 = 12;
const int golplayer1 = 13;
const int buttonplayer1 = 3;

const int player2 = 5;
const int golplayer2 = 4;
const int buttonplayer2 = 2;

int scoreplayer1 = 0;
int scoreplayer2 = 0;

const unsigned long inicialMillisegundosPorLED = 500;
const unsigned long inicialDeltaMillisegundosPorLED = 50;
unsigned long millisegundosPorLED = inicialMillisegundosPorLED;
unsigned long deltamillisegundosPorLED = inicialDeltaMillisegundosPorLED;
unsigned long atualMillis = 0;
unsigned long anteriorMillis = 0;

int PosicaoAtual = player1;        //Player 1 inicia o jogo.
int PosicaoAnterior = player1 + 1;
int deltaPosicao = 0;

int EstadoAtualButtonPlayer1 = 0;
int EstadoAnteriorButtonPlayer1 = 0;
int EstadoAtualButtonPlayer2 = 0;
int EstadoAnteriorButtonPlayer2 = 0;

//#### PROTÓTIPOS DAS FUNÇÕES ##############################################
void VerificarEntradas();
void MudaDirecaoDaBola();
void MoveBolaParaProximaPosicao();
void DeterminaProximaPosicao();
void ChecaGols();
void PontuacaoParaPlayer(int pontuador);
void ChecaFimDoJogo();
void MostraScores(int jogadorAtualPontuado);
void ResetJogada();
void FimDoJogo(int Vencedor);
void LigaTodosOsLEDsParaPlayer(int player);
void desligaTodosOsLEDsParaPlayer(int player);
void FlashLEDs(int blinkCount, int player);

//#### LOOP E SETUP ##############################################
void setup() {
  //Configura Pinos 4 a 13 como SAÍDAS (LEDS)
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  //Configura Pinos 2 e 3 como ENTRADAS (BOTÕES) com Resistor PullUp ativado
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
}

void loop(){
  VerificarEntradas();
  atualMillis = millis();
  if (atualMillis - anteriorMillis >= millisegundosPorLED){
    ChecaGols();
    DeterminaProximaPosicao();
    MoveBolaParaProximaPosicao();

    anteriorMillis = atualMillis;
  }
}

//#### FUNÇÕES #############################################################
void VerificarEntradas(){
  EstadoAtualButtonPlayer1 = digitalRead(buttonplayer1);
  EstadoAtualButtonPlayer2 = digitalRead(buttonplayer2);

  if (EstadoAtualButtonPlayer1 != EstadoAnteriorButtonPlayer1 && EntradaPermitida){
    if (EstadoAtualButtonPlayer1 == 1){
      if (PosicaoAtual == player1){
        MudaDirecaoDaBola();
        IncreaseSpeed();
      }else{
        PontuacaoParaPlayer(2);
      }
    }
    EstadoAnteriorButtonPlayer1 = EstadoAtualButtonPlayer1;
  }
  if (EstadoAtualButtonPlayer2 != EstadoAnteriorButtonPlayer2 && EntradaPermitida){
    if (EstadoAtualButtonPlayer2 == 1){
      if (PosicaoAtual == player2){
        MudaDirecaoDaBola();
        IncreaseSpeed();
      }else{
        PontuacaoParaPlayer(1);
      }
    }
    EstadoAnteriorButtonPlayer2 = EstadoAtualButtonPlayer2;
  }
}

void MudaDirecaoDaBola(){
  BolaVaiParaPlayer2 = !BolaVaiParaPlayer2;
  EntradaPermitida = false;   //Apenas uma mudança de direção por quadro é permitida para uma jogabilidade consistente.
}

void IncreaseSpeed(){
  millisegundosPorLED -= deltamillisegundosPorLED;
  if (deltamillisegundosPorLED > 5){  //Isto impede que atinja uma velocidade insana rapidamente. Ajuste ou remova isto se as rodadas ficarem muito longas.
    deltamillisegundosPorLED -= 5; 
  }
}

void MoveBolaParaProximaPosicao(){      //Move a bola uma posição
  PosicaoAnterior = PosicaoAtual;
  digitalWrite(PosicaoAnterior, 0);
  PosicaoAtual = PosicaoAtual + deltaPosicao;
  digitalWrite(PosicaoAtual, 1);
  EntradaPermitida = true;
}

void DeterminaProximaPosicao(){
  if (BolaVaiParaPlayer2){
    deltaPosicao = -1;
  }else{
    deltaPosicao = 1;
  }
}

void ChecaGols(){
  if (PosicaoAtual == golplayer2){
    PontuacaoParaPlayer(1);
  }else if (PosicaoAtual == golplayer1){
    PontuacaoParaPlayer(2);
  }
}

void PontuacaoParaPlayer(int pontuador){
  EntradaPermitida = false;
  FlashLEDs(1, 0);
  if (pontuador == 1){
    scoreplayer1++;
    MostraScores(1);
  }else if (pontuador == 2){
    scoreplayer2++;
    MostraScores(2);
  }
  ChecaFimDoJogo();
}

void ChecaFimDoJogo(){
  if (scoreplayer1 == 3){
    FimDoJogo(1);
  }
  if (scoreplayer2 == 3){
    FimDoJogo(2);
  }
}

void MostraScores(int jogadorAtualPontuado){
  if (jogadorAtualPontuado == 1){
    digitalWrite(player1, 1);
    PosicaoAtual = player1;
    BolaVaiParaPlayer2 = true;
  }else if (jogadorAtualPontuado == 2){
    digitalWrite(player2, 1);
    PosicaoAtual = player2;
    BolaVaiParaPlayer2 = false;
  }

  for (int i = 0; i < scoreplayer1; i++){ //Usamos os seis LEDs no meio para mostrar a pontuação. Cada Player tem três LEDs verdes para mostrar a pontuação. Com três gols vence o jogo.  
    digitalWrite((11 - i), 1);
  }
  for (int i = 0; i < scoreplayer2; i++){
    digitalWrite((6 + i), 1);
  }
  delay(3000);                //Três segundos para que os Players vizualizem a pontuação  
  ResetJogada();
}

void ResetJogada(){
  FlashLEDs(1, 0);
  millisegundosPorLED = inicialMillisegundosPorLED;            //Define a velocidade para o valor inicial no início de cada rodada.
  deltamillisegundosPorLED = inicialDeltaMillisegundosPorLED;  //Define a velocidade delta para o valor inicial no início de cada rodada.
}

void FimDoJogo(int Vencedor){
  FlashLEDs(50, Vencedor);
  desligaTodosOsLEDsParaPlayer(0);
  scoreplayer1 = 0;
  scoreplayer2 = 0;
}

void LigaTodosOsLEDsParaPlayer(int player){
  if (player != 1){         //Quando esse método é chamado com (2), somente esses pinos (Player 2) serão ativados
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }
  if (player != 2){          //Quando este método é chamado com (1), somente esses pinos (Player 1) vão ligar
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
  }
}

void desligaTodosOsLEDsParaPlayer(int player){
  if (player != 1){          //Quando esse método é chamado com (2), somente esses pinos (Player 2) serão desativados
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
  }
  if (player != 2){          //Quando este método é chamado com (1), somente esses pinos (Player 1) serão desativados
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
}

void FlashLEDs(int blinkCount, int player){ //O segundo parâmetro (int player) serve para quando você quer piscar apenas os LEDs de um Player. Use 1 para o Player 1, use 2 para o Player 2.
  for (int i = 0; i < blinkCount; i++){
    LigaTodosOsLEDsParaPlayer(player);
    delay(35);
    desligaTodosOsLEDsParaPlayer(player);
    delay(35);
  }
}
//#### FIM ##############################################

