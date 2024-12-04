import os
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

# Carregar os dados
df = pd.read_csv('datasets/analise10000.csv')
X = df['Tamanho da árvore'].values
y = df['Depreciação'].values

# Verifique se há valores ausentes
if np.any(np.isnan(X)) or np.any(np.isnan(y)):
    print("Há valores ausentes nos dados. Por favor, verifique.")
    exit()

# Encontrar automaticamente o valor mínimo e máximo de X e y
min_x = np.min(X)
max_x = np.max(X)
min_y = np.min(y)
max_y = np.max(y)

# Exibir os valores encontrados
print(f"Valor mínimo de X: {min_x}")
print(f"Valor máximo de X: {max_x}")
print(f"Valor mínimo de y: {min_y}")
print(f"Valor máximo de y: {max_y}")

# Definir a função logarítmica ajustável
def func_logaritmica_ajustada(x, a, b, c, d):
    # Garantir que o argumento do log seja maior que zero
    return a * np.log(np.maximum(b * x + c, 1e-6)) + d

# Normalizar X e y usando os valores encontrados
X_normalizado = (X - min_x) / (max_x - min_x)
y_normalizado = (y - min_y) / (max_y - min_y)

# Inicializar deslocamento para evitar problemas no log
deslocamento = abs(min_x) + 1 if min_x <= 0 else 1  # Garantir deslocamento inicial positivo

# Ajustar o modelo aos dados normalizados
try:
    params, _ = curve_fit(func_logaritmica_ajustada, X_normalizado, y_normalizado, p0=(1, 1, deslocamento, 0), maxfev=10000)
    a, b, c, d = params
    print(f"Parâmetros ajustados: a={a:.4f}, b={b:.4f}, c={c:.4f}, d={d:.4f}")
    print(f"Equação ajustada: y = {a:.4f} * ln({b:.4f} * x + {c:.4f}) + {d:.4f}")

    # Predições com o modelo ajustado
    y_pred_normalizado = func_logaritmica_ajustada(X_normalizado, a, b, c, d)

    # Desnormalizar y_pred para voltar à escala original de y
    y_pred = y_pred_normalizado * (max_y - min_y) + min_y

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
    filename = f"analiseDeCrescimento{max_x}.png"
    output_path = os.path.join(output_dir, filename)
    plt.savefig(output_path, dpi=300)
    print(f"Gráfico salvo em: {output_path}")
    
    # Mostrar o gráfico
    plt.show()

except RuntimeError as e:
    print(f"Erro ao ajustar a curva: {e}")
