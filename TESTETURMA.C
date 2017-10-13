/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              TESTETURMA.C
*  Letras identificadoras:      TTUR
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: cgln - Cristiane - Guilherme - Leonardo - Nathália
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações 
*       2.00   cgln  09/09/2017 Eliminação de código duplicado, reestruturação,
*                               inicio da implementação dos scripts e testes.
*       1.00   cgln  08/09/2017 Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este mÇodulo contém as funções específicas para o teste do
*     módulo turma. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo turma:
*
*     "=criar"           - chama a função TUR_CriaTurma( )
*     "=alterarHorIni"   - chama a função TUR_AlteraHorarioInicio( )
*     "=alterarHorFin"   - chama a função TUR_AlteraHorarioFinal( )
*     "=alterarDia"      - chama a função TUR_AlteraDia( )
*     "=alterarCodigo"   - chama a função TUR_AlteraCodigo( )
*     "=alterarVaga"     - chama a função TUR_AlteraQtdVaga( )
*     "=obterCodido"     - chama a função TUR_GetCodigo ( )
*     "=obterHorIni"     - chama a função TUR_GetHorIni ( )
*     "=obterHorFin"     - chama a função TUR_GetHorFin ( )
*     "=obterDia"        - chama a função TUR_GetDiaSem ( )
*     "=obterVaga"       - chama a função TUR_GetQtdVaga ( )
*     "=obterTurma"      - chama a função TUR_GetTurma( )
*     "=exibir"          - chama a função TUR_ExibeTurma( )
*     "=excluir"         - chama a função TUR_ExcluiTurma( )
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "TURMA.h"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_TUR_CMD       "=criar"
#define     ALT_HOR_INI_CMD     "=alterarHorIni"
#define     ALT_HOR_FIN_CMD     "=alterarHorFin"
#define     ALT_DIA_CMD         "=alterarDia"
#define     ALT_COD_CMD         "=alterarCodigo"
#define     ALT_QTD_VAG_CMD     "=alterarVaga"
#define     GET_COD_CMD         "=obterCodido"
#define     GET_HOR_INI_CMD     "=obterHorIni"
#define     GET_HOR_FIN_CMD     "=obterHorFin"
#define     GET_DIA_CMD         "=obterDia"
#define     GET_QTD_VAG_CMD     "=obterVaga"
#define     GET_TUR_CMD         "=obterTurma"
#define     EXIBIR_TUR_CMD      "=exibir"
#define     EXCLUIR_TUR_CMD     "=excluir"

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TTUR Efetuar operações de teste específicas para o módulo turma
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     turma sendo testado.
*
*  $EP Parâmetros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/

#define MAX_TUR 5

Turma *turma[MAX_TUR] = { NULL, NULL, NULL, NULL, NULL } ;

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      TUR_tpCondRet CondRetObtido ;
      TUR_tpCondRet CondRetEsperada ;
          
	  int index = 0 ;

	  char CodTurma[4] ;

	  int HorarioInicio ;

	  int HorarioTermino ;

	  char DiaSemana[28] ;

	  int QtdVaga ;

	  int ValorEsperado ;
      int ValorObtido ;
	  int ValorObtidoHorIni ; 
	  int ValorObtidoHorFin ;
	  int ValorObtidoQtd ; 
      char ValorStringObtido[80] ;
	  char ValorStringObtidoCod[4] ;
	  char ValorStringObtidoSem[28] ; 
	  char ValorStringEsperado[80] ; 

      int  NumLidos = -1 ;

      TST_tpCondRet Ret ;

      /* Testar TUR Criar turma */

         if ( strcmp( ComandoTeste , CRIAR_TUR_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "isiisii" ,
								&index, CodTurma, &HorarioInicio, &HorarioTermino,
								DiaSemana, &QtdVaga, &CondRetEsperada ) ;
            if ( NumLidos != 7 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = TUR_CriaTurma( turma+index, CodTurma, HorarioInicio,
				HorarioTermino, DiaSemana, QtdVaga ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar turma." ) ;

         } /* fim ativa: Testar TUR Criar turma */


      /* Testar TUR Alterar horário de inicio */

         else if ( strcmp( ComandoTeste , ALT_HOR_INI_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "iii" ,
								&index , &HorarioInicio, &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = TUR_AlteraHorarioInicio(turma[index], HorarioInicio) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao alterar horário de inicio." ) ;

         } /* fim ativa: Testar TUR Alterar horário de inicio */


	/* Testar TUR Alterar horário final */

         else if ( strcmp( ComandoTeste , ALT_HOR_FIN_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "iii" ,
								&index , &HorarioTermino, &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = TUR_AlteraHorarioFinal(turma[index], HorarioTermino) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao alterar horário final." ) ;

         } /* fim ativa: Testar TUR Alterar horário final */


      /* Testar TUR Altera dia da semana */

         else if ( strcmp( ComandoTeste , ALT_DIA_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "isi" ,
								&index, DiaSemana, &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = TUR_AlteraDia( turma[index], DiaSemana ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao alterar o dia da semana." ) ;

         } /* fim ativa: Testar TUR ALtera dia da semana */

      /* Testar TUR Altera Código */

         else if ( strcmp( ComandoTeste , ALT_COD_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "isi" ,
								&index, CodTurma, &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = TUR_AlteraCodigo( turma[index], CodTurma ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao alterar o código." ) ;

         } /* fim ativa: Testar TUR Altera Código */

      /* Testar TUR Altera quantidade de vagas*/

         else if ( strcmp( ComandoTeste , ALT_QTD_VAG_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "iii" ,
								&index, &QtdVaga, &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = TUR_AlteraQtdVaga( turma[index], QtdVaga ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao alterar a quantidade de vagas." ) ;

         } /* fim ativa: Testar TUR Altera quantidade de vagas */

		 		 
      /* Testar TUR Exibe turma */

         else if ( strcmp( ComandoTeste ,EXIBIR_TUR_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" ,
								&index, &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = TUR_ExibeTurma( turma[index] ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                   "Retorno errado ao exibir turma." );
			
         } /* fim ativa: Testar TUR Exibe turma */


      /* Testar TUR Get codigo turma */

		 else if( strcmp( ComandoTeste , GET_COD_CMD ) == 0 ) 
		{

			NumLidos = LER_LerParametros( "isi" ,
                               &index, CodTurma , &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtido = TUR_GetCodigo( turma[index], ValorStringObtido) ;

            Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                   "Retorno errado ao obter codigo da turma." );
            if ( Ret != TST_CondRetOK )
            {
               return Ret ;
            } /* if */

			return TST_CompararString( CodTurma, ValorStringObtido ,
                                     "Conteudo errado no codigo da turma." ) ;

         } /* fim ativa: Testar TUR Get codigo turma */

		 
      /* Testar TUR Get horario inicio */

		 else if( strcmp( ComandoTeste , GET_HOR_INI_CMD ) == 0 ) 
		{

			NumLidos = LER_LerParametros( "iii" ,
                               &index, &HorarioInicio , &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtido = TUR_GetHorIni( turma[index], &ValorObtido) ;

            Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                   "Retorno errado ao obter horario inicio da turma." );
            if ( Ret != TST_CondRetOK )
            {
               return Ret ;
            } /* if */

			return TST_CompararInt( HorarioInicio, ValorObtido ,
                                     "Conteudo errado no horario inicio da turma." ) ;

         } /* fim ativa: Testar TUR Get horario inicio */


	/* Testar TUR Get horario final */

		 else if( strcmp( ComandoTeste , GET_HOR_FIN_CMD ) == 0 ) 
		{

			NumLidos = LER_LerParametros( "iii" ,
                               &index, &HorarioTermino , &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtido = TUR_GetHorFin( turma[index], &ValorObtido) ;

            Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                   "Retorno errado ao obter horario final da turma." );
            if ( Ret != TST_CondRetOK )
            {
               return Ret ;
            } /* if */

			return TST_CompararInt( HorarioTermino, ValorObtido ,
                                     "Conteudo errado no horario final da turma." ) ;

         } /* fim ativa: Testar TUR Get horario final */


	/* Testar TUR Get Dia Semana */

		 else if( strcmp( ComandoTeste , GET_DIA_CMD ) == 0 ) 
		{

			NumLidos = LER_LerParametros( "isi" ,
                               &index, DiaSemana , &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtido = TUR_GetDiaSem( turma[index], ValorStringObtido) ;

            Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                   "Retorno errado ao obter dia da semana da turma." ) ;
            if ( Ret != TST_CondRetOK )
            {
               return Ret ;
            } /* if */

			return TST_CompararString( DiaSemana, ValorStringObtido ,
                                     "Conteudo errado no dia da semana da turma." ) ;

         } /* fim ativa: Testar TUR Get Dia Semana */


      /* Testar TUR Get quantidade de vaga */

		 else if( strcmp( ComandoTeste , GET_QTD_VAG_CMD ) == 0 ) 
		{

			NumLidos = LER_LerParametros( "iii" ,
                               &index, &QtdVaga , &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtido = TUR_GetQtdVaga( turma[index], &ValorObtido ) ;

            Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                   "Retorno errado na quantidade de vaga da turma." ) ;
            if ( Ret != TST_CondRetOK )
            {
               return Ret ;
            } /* if */

			return TST_CompararInt( QtdVaga, ValorObtido ,
                                     "Conteudo errado na quantidade de vaga da turma." ) ;

         } /* fim ativa: Testar TUR Get quantidade de vaga */


   /* Testar TUR Get turma*/

        else if ( strcmp( ComandoTeste , GET_TUR_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "isiisii" , 
								&index, CodTurma, &HorarioInicio, &HorarioTermino,
								DiaSemana, &QtdVaga, &CondRetEsperada ) ;
            if ( NumLidos != 7 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = TUR_GetTurma( turma[index], ValorStringObtidoCod, 
				&ValorObtidoHorIni, &ValorObtidoHorFin, ValorStringObtidoSem, &ValorObtidoQtd ) ;

			Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                   "Retorno errado no get turma." ) ;
            if ( Ret != TST_CondRetOK )
            {
               return Ret ;
            } /* if */

			return TST_CompararString( CodTurma, ValorStringObtidoCod ,
                                     "Conteudo errado no codigo da get turma." ) ;

			return TST_CompararInt( HorarioInicio, ValorObtidoHorIni ,
                                     "Conteudo errado no horario inicio da get turma." ) ;

            return TST_CompararInt( HorarioTermino, ValorObtidoHorFin ,
                                     "Conteudo errado no horario final da get turma." ) ;
			
			return TST_CompararString( DiaSemana, ValorStringObtidoSem ,
                                     "Conteudo errado no dia da semana da get turma." ) ;

			return TST_CompararInt( QtdVaga, ValorObtidoQtd ,
                                     "Conteudo errado na quantidade de vaga da get turma." ) ;

         } /* fim ativa: Testar TUR Get turma */
		 		 

   /* Testar TUR Exclui turma*/

        else if ( strcmp( ComandoTeste , EXCLUIR_TUR_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" ,
								&index, &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = TUR_ExcluiTurma( turma[index] ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao excluir turma." );

         } /* fim ativa: Testar TUR Exclui turma */

	} /* Fim função: TTUR Efetuar operações de teste específicas para o módulo turma */

/********** Fim do módulo de implementação: Módulo de teste específico **********/