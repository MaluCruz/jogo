 // Inicialização do jogo
 let componentes = Array.from(Array(10).keys()); // Cria um array de 0 a 9
 let posicaoAtual = 0;
 let peca = Math.floor(Math.random() * 10); // Escolhe aleatoriamente a posição da peça
 let codigoSecreto = 224;
 let jogoAtivo = true; // Controla o estado do jogo

 function atualizarStatus() {
     document.getElementById('status').innerText = `Você está na posição ${posicaoAtual} da máquina.`;
 }

 function verificarPeca() {
     const messageElement = document.getElementById('message');
     if (posicaoAtual === peca) {
         messageElement.innerText = "Parabéns! Você encontrou a peça!";
     } else {
         messageElement.innerText = "Não há peça nesta posição. Continue procurando!";
     }
 }

 document.getElementById('submitBtn').addEventListener('click', () => {
     if (!jogoAtivo) return; // Se o jogo não estiver ativo, não faz nada

     const opcao = parseInt(document.getElementById('inputOpcao').value);
     
     if (opcao >= 0 && opcao <= 9) {
         posicaoAtual = opcao; // Atualiza a posição atual do jogador
         verificarPeca(); // Verifica se a peça foi encontrada
         atualizarStatus(); // Atualiza o status na tela
     } else {
         document.getElementById('message').innerText = "Opção inválida. Tente novamente.";
     }
 });

 document.getElementById('secretBtn').addEventListener('click', () => {
     const codigoEntrada = parseInt(document.getElementById('inputCodigo').value);
     if (codigoEntrada === codigoSecreto) {
         document.getElementById('message').innerText = "Código secreto inserido! O jogo foi finalizado.";
         jogoAtivo = false; // Finaliza o jogo
         posicaoAtual = -1; // Atualiza a posição para indicar que o jogo acabou
         atualizarStatus();
     } else {
         document.getElementById('message').innerText = "Código secreto inválido. Tente novamente.";
     }
 });

 // Inicializa o status na tela
 atualizarStatus()