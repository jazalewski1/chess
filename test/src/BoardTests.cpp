#include "logic/ChessBoard.hpp"
#include "logic/Piece.hpp"
#include "util/Vector2.hpp"
#include "util/Exception.hpp"
#include <gtest/gtest.h>
#include <type_traits>

TEST(BoardTests, Get_Piece_Bishop_From_Valid_Position)
{
	const auto sut = logic::ChessBoard{};
	const auto position = util::Vector2i{2, 0};

	const auto piece = sut.get_piece_at(position);
	const auto expected = logic::State::BISHOP;

	EXPECT_EQ(piece, expected);
}

TEST(BoardTests, Get_Piece_Pawn_From_Valid_Position)
{
	const auto sut = logic::ChessBoard{};
	const auto position = util::Vector2i{4, 1};

	const auto piece = sut.get_piece_at(position);
	const auto expected = logic::State::PAWN;

	EXPECT_EQ(piece, expected);
}

TEST(BoardTests, Get_Piece_Empty_From_Valid_Position)
{
	const auto sut = logic::ChessBoard{};
	const auto position = util::Vector2i{4, 4};

	const auto piece = sut.get_piece_at(position);
	const auto expected = logic::State::EMPTY;

	EXPECT_EQ(piece, expected);
}

TEST(BoardTests, Try_Get_Piece_From_Bounds_Doesnt_Throw)
{
	const auto sut = logic::ChessBoard{};
	const auto position = util::Vector2i{7, 6};

	EXPECT_NO_THROW(sut.get_piece_at(position));
}

TEST(BoardTests, Try_Get_Piece_From_Out_Of_Bounds_Throws)
{
	const auto sut = logic::ChessBoard{};
	const auto position = util::Vector2i{8, 6};

	EXPECT_THROW(sut.get_piece_at(position), util::OutOfBoundsException);
}

TEST(BoardTests, Try_Get_Piece_From_Negative_Out_Of_Bounds_Throws)
{
	const auto sut = logic::ChessBoard{};
	const auto position = util::Vector2i{-2, 3};

	EXPECT_THROW(sut.get_piece_at(position), util::OutOfBoundsException);
}

TEST(BoardTests, Move_Piece_From_Valid_Position_To_Valid_Position)
{
	auto sut = logic::ChessBoard{};
	const auto source = util::Vector2i{2, 0};
	const auto destination = util::Vector2i{5, 4};

	const auto source_before = sut.get_piece_at(source);
	const auto destination_before = sut.get_piece_at(destination);

	EXPECT_NO_THROW(sut.move_piece(source, destination));

	const auto source_after = sut.get_piece_at(source);
	const auto destination_after = sut.get_piece_at(destination);

	EXPECT_EQ(source_after, destination_before);
	EXPECT_EQ(destination_after, source_before);
}

TEST(BoardTests, Try_Move_Piece_From_Invalid_Position_To_Valid_Position)
{
	auto sut = logic::ChessBoard{};
	const auto bad_source = util::Vector2i{12, 4};
	const auto destination = util::Vector2i{3, 3};

	EXPECT_THROW(sut.move_piece(bad_source, destination), util::OutOfBoundsException);
}

TEST(BoardTests, Try_Move_Piece_From_Valid_Position_To_Invalid_Position)
{
	auto sut = logic::ChessBoard{};
	const auto source = util::Vector2i{2, 2};
	const auto bad_destination = util::Vector2i{1, 8};

	EXPECT_THROW(sut.move_piece(source, bad_destination), util::OutOfBoundsException);
}