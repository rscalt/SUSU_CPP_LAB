        {
          //костыльный swap для элементов двумерного массива
          next_profit = profit_array[line_index + 1][profit_column_profit - 1];
          prev_profit = profit_array[line_index][profit_column_profit - 1];
          swap_values(next_profit, prev_profit);
          profit_array[line_index + 1][profit_column_profit - 1] = next_profit;
          profit_array[line_index][profit_column_profit - 1] = prev_profit;

          next_id = profit_array[line_index + 1][profit_column_id - 1];
          prev_id = profit_array[line_index][profit_column_id - 1];
          swap_values(next_id, prev_id);
          profit_array[line_index + 1][profit_column_id - 1] = next_id;
          profit_array[line_index][profit_column_id - 1] = prev_id;
        }