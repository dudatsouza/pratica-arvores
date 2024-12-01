# import pandas as pd
# import plotly.graph_objects as go
# import plotly.io as pio

# # Carregar os dados do arquivo CSV
# df = pd.read_csv('datasets/analise.csv')

# # Criar o gráfico de linha com base nos dados
# fig = go.Figure()

# # Adicionar as linhas ao gráfico
# fig.add_trace(go.Scatter(
#     x=df['Tamanho da árvore'],
#     y=df['Depreciação'],
#     mode='lines+markers',
#     name='Depreciação',
#     marker=dict(size=10)  # Define o tamanho das bolinhas
# ))

# # Configurar layout do gráfico
# fig.update_layout(
#     title={
#         'text': 'Relação entre Tamanho da Árvore e Depreciação',
#         'x': 0.5,
#         'xanchor': 'center',
#         'yanchor': 'top',
#         'font': {'family': 'Courier New', 'size': 30, 'color': 'white'}
#     },
#     xaxis_title='Tamanho da Árvore',
#     yaxis_title='Depreciação',
#     font=dict(
#         family="sans-serif",
#         size=14,
#         color="#7f7f7f"
#     ),
#     paper_bgcolor="black",
#     plot_bgcolor="black",
#     legend=dict(
#         x=1,
#         y=1,
#         traceorder='normal',
#         font=dict(
#             family='sans-serif',
#             size=12,
#             color='white'
#         ),
#         bgcolor='black',
#         bordercolor='black',
#         borderwidth=1
#     ),
#     xaxis=dict(
#         gridcolor='rgba(255, 255, 255, 0.2)'  # Cor branca com 20% de opacidade
#     ),
#     yaxis=dict(
#         gridcolor='rgba(255, 255, 255, 0.2)'  # Cor branca com 20% de opacidade
#     )
# )

# # Adicionar anotação com legenda abaixo do título
# fig.add_annotation(
#     text="Tamanho da Árvore x Depreciação",
#     xref="paper", yref="paper",
#     x=0.5, y=1.02,  # Posiciona a anotação acima do gráfico
#     showarrow=False,
#     font=dict(
#         family="Courier New",
#         size=18,
#         color="rgba(255, 255, 255, 1)"  # Cor da anotação
#     ),
#     align="center"
# )

# # Exibir o gráfico
# fig.show()

# # Salvar o gráfico como PNG
# file_name = f"datasets/graphs/analise.png"
# pio.write_image(fig, file_name, format='png', width=1280, height=720)
# print(f"Gráfico salvo como {file_name}")

import os
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

# Carregar os dados
df = pd.read_csv('datasets/analise.csv')
X = df['Tamanho da árvore'].values
y = df['Depreciação'].values

# Definir a função logarítmica ajustável
def func_logaritmica_ajustada(x, a, b, c, d):
    # Garantir que o argumento do log seja maior que zero
    return a * np.log(np.maximum(b * x + c, 1e-6)) + d

# Inicializar deslocamento para evitar problemas no log
min_x = np.min(X)
deslocamento = abs(min_x) + 1 if min_x <= 0 else 1  # Garantir deslocamento inicial positivo

# Ajustar o modelo aos dados
try:
    params, _ = curve_fit(func_logaritmica_ajustada, X, y, p0=(1, 1, deslocamento, 0), maxfev=10000)
    a, b, c, d = params
    print(f"Parâmetros ajustados: a={a:.4f}, b={b:.4f}, c={c:.4f}, d={d:.4f}")
    print(f"Equação ajustada: y = {a:.4f} * ln({b:.4f} * x + {c:.4f}) + {d:.4f}")

    # Predições com o modelo ajustado
    y_pred = func_logaritmica_ajustada(X, a, b, c, d)

    # Visualizar os dados reais e o ajuste
    plt.figure(figsize=(10, 6))
    plt.scatter(X, y, label='Dados Reais', color='black')
    plt.plot(X, y_pred, label='Regressão Logarítmica', color='red', linewidth=2)
    plt.title('Análise de Crescimento de Árvores')
    plt.xlabel('Tamanho da Árvore')
    plt.ylabel('Depreciação')
    plt.legend()
    plt.grid(True, linestyle='--', alpha=0.7)

    # Criar o diretório se não existir
    output_dir = "datasets/graphs"
    os.makedirs(output_dir, exist_ok=True)

    # Salvar a imagem do gráfico
    output_path = os.path.join(output_dir, "analiseDeCrescimento.png")
    plt.savefig(output_path, dpi=300)
    print(f"Gráfico salvo em: {output_path}")
    
    # Mostrar o gráfico
    plt.show()

except RuntimeError as e:
    print(f"Erro ao ajustar a curva: {e}")
