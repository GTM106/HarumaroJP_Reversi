#pragma once

#include "Basic.h"
#include <intrin.h>
#include <bit>
#include <bitset>
#include <cstdint>
#include <iostream>
#include <memory>
#include <span>

namespace Reversi
{
	struct BoardInfo
	{
		int black_count;
		int white_count;
		bool is_end;
	};

	class Board
	{
	public:
		Board();

		/// <summary>
		/// �Ֆʂɐ΂��Z�b�g���܂�
		/// </summary>
		/// <param name="input">�Z�b�g�ʒu</param>
		/// <param name="side">�Z�b�g���鑤</param>
		void Set(u64 input, Side side);

		/// <summary>
		/// �w�肵���ʒu�̐΂𔽓]���A���]�ʒu���擾���܂��B
		/// </summary>
		/// <param name="input">�ݒu�ʒu</param>
		/// <param name="side">���]���鑤</param>
		/// <returns>���]�ʒu</returns>
		u64 Flip(u64 input, Side side);

		/// <summary>
		/// �w�肵���ʒu�̐Ώ��������߂��܂�
		/// </summary>
		/// <param name="input">�����߂��ʒu</param>
		/// <param name="side">�Z�b�g������</param>
		void Undo(u64 input, Side side);

		/// <summary>
		/// �w�肵���ꏊ����ɂ��܂�
		/// </summary>
		/// <param name="input">��ɂ���ʒu</param>
		void SetEmpty(u64 input);

		/// <summary>
		/// �΂̐����擾���܂�
		/// </summary>
		/// <returns>���ԂƔ��Ԃ̐΂̐�</returns>
		std::pair<int, int> CountStone() const;

		/// <summary>
		/// ����\�����擾���܂�
		/// </summary>
		/// <returns>���ԂƔ��Ԃ̒���\��</returns>
		std::pair<int, int> CountLegalMoves() const;

		/// <summary>
		/// �΂��u����Ă���ʒu���擾���܂�
		/// </summary>
		/// <returns>�΂��u����Ă���ʒu</returns>
		u64 GetAllBoard() const;

		/// <summary>
		/// ����\�ʒu���擾���܂�
		/// </summary>
		/// <param name="side">����\��</param>
		/// <returns>����\�ʒu</returns>
		u64 GetLegalMoves(Side side) const;

		/// <summary>
		/// �w�肵���ʒu����\���Ɍq�������}�X���擾���܂�
		/// </summary>
		/// <param name="input">��ʒu</param>
		/// <param name="others">�擾���鑤</param>
		/// <returns>�q�������}�X�̏��</returns>
		u64 GetCrossFloods(u64 input, u64 others) const;

		/// <summary>
		/// �Ֆʏ����擾���܂�
		/// </summary>
		/// <returns>���ԂƔ��Ԃ̔Ֆʏ��</returns>
		std::pair<u64, u64> GetFieldData() const;

		/// <summary>
		/// �Ֆʏ��̃��Z�b�g���s���܂�
		/// </summary>
		void Reset();

		/// <summary>
		/// �Ֆʏ����㏑�����܂�
		/// </summary>
		/// <param name="board">�㏑��������</param>
		void Overwrite(const Board& board);

	private:
		u64 black_board;
		u64 white_board;

		static constexpr u64 horizontal_mask = 0x7e7e7e7e7e7e7e7e;
		static constexpr u64 vertical_mask = 0x00FFFFFFFFFFFF00;
		static constexpr u64 allSide_mask = horizontal_mask & vertical_mask;

		u64 GetVerticalMoves(u64 mine, u64 others, u64 empties) const;
		u64 GetHorizontalMoves(u64 mine, u64 others, u64 empties) const;
		u64 GetCrossMoves(u64 mine, u64 others, u64 empties) const;

		u64 GetVerticalFlips(u64 input, u64 mine, u64 others) const;
		u64 GetHorizontalFlips(u64 input, u64 mine, u64 others) const;
		u64 GetDiagonalCrossFlips(u64 input, u64 mine, u64 others) const;
	};
}

