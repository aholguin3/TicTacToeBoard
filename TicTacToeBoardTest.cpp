/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, toggle_testOnce)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.toggleTurn(), O);
}

TEST(TicTacToeBoardTest, toggle_testTwice)
{
	TicTacToeBoard board;
	board.toggleTurn();
	ASSERT_EQ(board.toggleTurn(), X);
}

TEST(TicTacToeBoardTest, placePiece_testOutBounds)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(5,10), Invalid);
}

TEST(TicTacToeBoardTest, placePiece_testTaken)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	ASSERT_EQ(board.placePiece(0,0), X);
}

TEST(TicTacToeBoard, getPiece_testBlank)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.getPiece(0,0), Blank);
}

TEST(TicTacToeBoardTest, getPiece_testX)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	ASSERT_EQ(board.getPiece(0,0), X);
}

TEST(TicTacToeBoardTest, getPiece_testOutBounds)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.getPiece(5,10), Invalid);
}


TEST(TicTacToeBoardTest, getWinner_testTopRow)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(1,0);
	board.placePiece(0,1);
	board.placePiece(1,2);
	board.placePiece(0,2);
	ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoard, getWinner_testMiddleRow)
{
	TicTacToeBoard board;
	board.placePiece(1,0);
	board.toggleTurn();
	board.placePiece(1,1);
	board.toggleTurn();
	board.placePiece(1,2);
	ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoard, getWinner_testBottomRow)
{
	TicTacToeBoard board;
	board.placePiece(2,0);
	board.toggleTurn();
	board.placePiece(2,1);
	board.toggleTurn();
	board.placePiece(2,2);
	ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoard, getWinner_testLeftColumn)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.toggleTurn();
	board.placePiece(1,0);
	board.toggleTurn();
	board.placePiece(2,0);
	ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoard, getWinner_testMiddleColumn)
{
	TicTacToeBoard board;
	board.placePiece(0,1);
	board.toggleTurn();
	board.placePiece(1,1);
	board.toggleTurn();
	board.placePiece(2,1);
	ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoard, getWinner_testRightColumn)
{
	TicTacToeBoard board;
	board.placePiece(0,2);
	board.toggleTurn();
	board.placePiece(1,2);
	board.toggleTurn();
	board.placePiece(2,2);
	ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoard, getWinner_testDiagonal1)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.toggleTurn();
	board.placePiece(1,1);
	board.toggleTurn();
	board.placePiece(2,2);
	ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoard, getWinner_testDiagonal2)
{
	TicTacToeBoard board;
	board.placePiece(0,2);
	board.toggleTurn();
	board.placePiece(1,1);
	board.toggleTurn();
	board.placePiece(2,0);
	ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoard, getWinner_testInvalid)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.getWinner(), Invalid);
}

TEST(TicTacToeBoard, getWinner_testDraw)
{
	TicTacToeBoard board;
	board.placePiece(2,0);
	board.placePiece(0,0);
	board.placePiece(0,1);
	board.placePiece(1,0);
	board.placePiece(1,1);
	board.placePiece(2,1);
	board.placePiece(1,2);
	board.placePiece(0,2);
	board.placePiece(2,2);
	ASSERT_EQ(board.getWinner(), Blank);
}