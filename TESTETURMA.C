/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste espec�fico
*
*  Arquivo gerado:              TESTETURMA.C
*  Letras identificadoras:      TTUR
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: cgln - Cristiane - Guilherme - Leonardo - Nath�lia
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es 
*       2.00   cgln  09/09/2017 Elimina��o de c�digo duplicado, reestrutura��o,
*                               inicio da implementa��o dos scripts e testes.
*       1.00   cgln  08/09/2017 In�cio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Este m�odulo cont�m as fun��es espec�ficas para o teste do
*     m�dulo turma. Ilustra como redigir um interpretador de comandos
*     de teste espec�ficos utilizando o arcabou�o de teste para C.
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo turma:
*
*     "=criar"           - chama a fun��o TUR_CriaTurma( )
*     "=alterarHorIni"   - chama a fun��o TUR_AlteraHorarioInicio( )
*     "=alterarHorFin"   - chama a fun��o TUR_AlteraHorarioFinal( )
*     "=alterarDia"      - chama a fun��o TUR_AlteraDia( )
*     "=alterarCodigo"   - chama a fun��o TUR_AlteraCodigo( )
*     "=alterarVaga"     - chama a fun��o TUR_AlteraQtdVaga( )
*     "=obterCodido"     - chama a fun��o TUR_GetCodigo ( )
*     "=obterHorIni"     - chama a fun��o TUR_GetHorIni ( )
*     "=obterHorFin"     - chama a fun��o TUR_GetHorFin ( )
*     "=obterDia"        - chama a fun��o TUR_GetDiaSem ( )
*     "=obterVaga"       - chama a fun��o TUR_GetQtdVaga ( )
*     "=obterTurma"      - chama a fun��o TUR_GetTurma( )
*     "=exibir"          - chama a fun��o TUR_ExibeTurma( )
*     "=excluir"         - chama a fun��o TUR_ExcluiTurma( )
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "TURMA.h"

/* Tabela dos nomes dos comandos de teste espec�ficos */

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

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TTUR Efetuar opera��es de teste espec�ficas para o m�dulo turma
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     turma sendo testado.
*
*  $EP Par�metros
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


      /* Testar TUR Alterar hor�rio de inicio */

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
                                    "Retorno errado ao alterar hor�rio de inicio." ) ;

         } /* fim ativa: Testar TUR Alterar hor�rio de inicio */


	/* Testar TUR Alterar hor�rio final */

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
                                    "Retorno errado ao alterar hor�rio final." ) ;

         } /* fim ativa: Testar TUR Alterar hor�rio final */


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

      /* Testar TUR Altera C�digo */

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
                                    "Retorno errado ao alterar o c�digo." ) ;

         } /* fim ativa: Testar TUR Altera C�digo */

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

	} /* Fim fun��o: TTUR Efetuar opera��es de teste espec�ficas para o m�dulo turma */

/********** Fim do m�dulo de implementa��o: M�dulo de teste espec�fico **********/